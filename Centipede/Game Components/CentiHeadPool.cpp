#include "CentiHeadPool.h"
#include "CentipedeHead.h"
#include "WaveManager.h"
#include "GameManager.h"

CentiHeadPool * CentiHeadPool::instance = nullptr;

CentipedeHead * CentiHeadPool::GetCentiHead()
{
	CentipedeHead* head;

	if (GetInstance()->headList.empty())
	{
		head = new CentipedeHead;
		head->SetExternalManagement(RecycleCentiBody);
	}

	else
	{
		head = GetInstance()->headList.front();
		GetInstance()->headList.pop_front();
		head->RegisterToCurrentScene();
	}

	instance->numActiveCenti++;
	return head;
}

void CentiHeadPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->numActiveCenti--;
	GetInstance()->headList.push_front(static_cast<CentipedeHead*>(body));
	
	if(instance->numActiveCenti <= 0)
		GameManager::EndWave();
}

void CentiHeadPool::EndWave()
{
	for(auto c : GetInstance()->headList)
	{
		c->MarkForDestroy(); //this may not work due to it being deleted before destroyed
//		delete c;
	}
}

void CentiHeadPool::Terminate()
{
		//for(auto c : this->headList)
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
