#include "CentiHeadPool.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "WaveManager.h"
#include "GameManager.h"

CentiHeadPool * CentiHeadPool::instance = nullptr;

CentipedeHead * CentiHeadPool::GetCentiHead()
{
	CentipedeHead* head;

	if (GetInstance()->inactiveHeadList.empty())
	{
		head = new CentipedeHead;
		head->SetExternalManagement(RecycleCentiHead);
	}

	else
	{
		head = GetInstance()->inactiveHeadList.front();
		GetInstance()->inactiveHeadList.pop_front();
		head->RegisterToCurrentScene();
	}
	
	instance->activeHeadList.push_back(head);
	instance->numActiveCenti++;
	return head;
}

void CentiHeadPool::RecycleCentiHead(GameObject * const head)
{
	GetInstance()->numActiveCenti--;
	instance->inactiveHeadList.push_front(static_cast<CentipedeHead*>(head));
	instance->activeHeadList.remove(static_cast<CentipedeHead*>(head));

	if (instance->activeHeadList.empty())
	{
		/**
		 * this check is a work around I did to confirm that this centipede was indeed shot
		 * and not instead recycled by the Terminate() sequence. This was required because otherwise,
		 * when the game is Terminate-ing(), this function gets called and EndWave() goes on forever
		 */
		if(static_cast<CentipedeHead*>(head)->GetConcent())
			GameManager::EndWave();
	}
}

void CentiHeadPool::EndWave()
{
	for (auto c : GetInstance()->activeHeadList)
	{
		CentipedeBody *tmp(static_cast<CentipedeBody*>(c->GetWhosFollowingYou())), *past(nullptr);

		while (tmp)
		{
			past = static_cast<CentipedeBody*>(tmp->GetWhosFollowingYou());
			tmp->MarkForDestroy();
			tmp = past;
		}
		c->MarkForDestroy();
	}
}

void CentiHeadPool::Terminate()
{
	for(auto c : GetInstance()->activeHeadList)
	{
		delete c;
		c = nullptr;
	}

	for(auto c : GetInstance()->inactiveHeadList)
	{
		delete c;
		c = nullptr;
	}

	delete instance;
	instance = nullptr;
}

CentiHeadPool * CentiHeadPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadPool;

	return instance;
}
