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
		head->SetExternalManagement(RecycleCentiBody);
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

void CentiHeadPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->numActiveCenti--;
	instance->inactiveHeadList.push_front(static_cast<CentipedeHead*>(body));
	instance->activeHeadList.remove(static_cast<CentipedeHead*>(body));

	if(instance->numActiveCenti <= 0)
	{
		if(!instance->bs)
		{
			GameManager::EndWave();
			instance->bs = true;
		}
	}
}

void CentiHeadPool::EndWave()
{
/*	for(auto c : GetInstance()->inactiveHeadList)
	{
		c->MarkForDestroy(); //this may not work due to it being deleted before destroyed
		//delete c;
	}
*/
	
	//todo: this works, this may want to be seperated tho
	for(auto c : GetInstance()->activeHeadList)
	{
		CentipedeBody *tmp, *past;
		tmp = static_cast<CentipedeBody*>(c->GetWhosFollowingYou());
		while(tmp)
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
		//for(auto c : this->inactiveHeadList)
		//delete c;

	delete instance;
	instance = nullptr;
}

CentiHeadPool * CentiHeadPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadPool;

	return instance;
}
