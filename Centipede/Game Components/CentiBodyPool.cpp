#include "CentiBodyPool.h"
#include "CentipedeBody.h"

CentiBodyPool * CentiBodyPool::instance = 0;

CentipedeBody * CentiBodyPool::GetCentiBody()
{
	CentipedeBody* body;

	if (GetInstance()->bodyList.size() == 0)
		body = new CentipedeBody;

	else
	{
		body = GetInstance()->bodyList.front();
		GetInstance()->bodyList.pop_front();
	}

	return body;
}

void CentiBodyPool::RecycleCentiBody(CentipedeBody * const body)
{
	GetInstance()->bodyList.push_front(body);
}

CentiBodyPool * CentiBodyPool::GetInstance()
{
	if (instance == 0)
		instance = new CentiBodyPool;

	return instance;
}
