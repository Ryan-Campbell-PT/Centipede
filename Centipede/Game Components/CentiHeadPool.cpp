#include "CentiHeadPool.h"
#include "CentipedeHead.h"

CentiHeadPool * CentiHeadPool::instance = 0;

CentipedeHead * CentiHeadPool::GetCentiHead() const
{
	CentipedeHead* head;

	if (GetInstance()->bodyList.size() == 0)
		head = new CentipedeHead;

	else
	{
		head = GetInstance()->bodyList.front();
		GetInstance()->bodyList.pop_front();
	}

	return head;
}

void CentiHeadPool::RecycleCentiBody(CentipedeHead * const body) const
{
	GetInstance()->bodyList.push_front(body);
}

CentiHeadPool * CentiHeadPool::GetInstance()
{
	if (instance == 0)
		instance = new CentiHeadPool;

	return instance;
}
