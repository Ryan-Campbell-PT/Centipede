#include "CentiBodyPool.h"
#include "CentipedeBody.h"

CentiBodyPool * CentiBodyPool::instance = nullptr;

CentipedeBody * CentiBodyPool::GetCentiBody()
{
	CentipedeBody* body;

	if (GetInstance()->bodyList.empty())
	{
		body = new CentipedeBody;
		body->SetExternalManagement(RecycleCentiBody);
	}

	else
	{
		body = GetInstance()->bodyList.front();
		GetInstance()->bodyList.pop_front();
		body->RegisterToCurrentScene();
	}

	return body;
}

void CentiBodyPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->bodyList.push_front(static_cast<CentipedeBody*>(body));
}

CentiBodyPool::~CentiBodyPool()
{
	for(auto c : this->bodyList)
		delete c;

	delete instance;
}

CentiBodyPool * CentiBodyPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyPool;

	return instance;
}
