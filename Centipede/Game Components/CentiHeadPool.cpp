#include "CentiHeadPool.h"
#include "CentipedeHead.h"

CentiHeadPool * CentiHeadPool::instance = nullptr;

CentipedeHead * CentiHeadPool::GetCentiHead()
{
	CentipedeHead* head;

	if (GetInstance()->headList.empty())
		head = new CentipedeHead;

	else
	{
		head = GetInstance()->headList.front();
		GetInstance()->headList.pop_front();
	}

	return head;
}

void CentiHeadPool::RecycleCentiBody(CentipedeHead * const body)
{
	GetInstance()->headList.push_front(body);
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
