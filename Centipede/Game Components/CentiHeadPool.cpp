#include "CentiHeadPool.h"
#include "CentipedeHead.h"
#include "WaveManager.h"

CentiHeadPool * CentiHeadPool::instance = nullptr;

CentipedeHead * CentiHeadPool::GetCentiHead()
{
	CentipedeHead* head;

	if (GetInstance()->headList.empty())
	{
		head = new CentipedeHead;
		head->SetExternalManagement(RecycleCentiBody);
		instance->numActiveCenti++;
	}

	else
	{
		head = GetInstance()->headList.front();
		GetInstance()->headList.pop_front();
		head->RegisterToCurrentScene();
	}

	return head;
}

void CentiHeadPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->numActiveCenti--;
	GetInstance()->headList.push_front(static_cast<CentipedeHead*>(body));
	
	if(instance->numActiveCenti <= 0)
		WaveManager::EndWave();
}

void CentiHeadPool::EndWave()
{
	for(auto c : GetInstance()->headList)
	{
		c->MarkForDestroy(); //this may not work due to it being deleted before destroyed
//		delete c;
	}
}

CentiHeadPool::~CentiHeadPool()
{
	for(auto c : this->headList)
		delete c;

	delete instance;
}

CentiHeadPool * CentiHeadPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadPool;

	return instance;
}
