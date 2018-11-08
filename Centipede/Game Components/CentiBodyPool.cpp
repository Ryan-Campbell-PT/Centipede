#include "CentiBodyPool.h"
#include "CentipedeBody.h"

CentiBodyPool * CentiBodyPool::instance = nullptr;

CentipedeBody * CentiBodyPool::GetCentiBody()
{
	CentipedeBody* body;

	if (GetInstance()->inactiveBodyList.empty())
	{
		body = new CentipedeBody;
		body->SetExternalManagement(RecycleCentiBody);
	}

	else
	{
		body = GetInstance()->inactiveBodyList.front();
		GetInstance()->inactiveBodyList.pop_front();
		body->RegisterToCurrentScene();
	}

	return body;
}

void CentiBodyPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->inactiveBodyList.push_front(static_cast<CentipedeBody*>(body));
}

void CentiBodyPool::Terminate()
{	
	//for(auto c : this->inactiveBodyList)
	//	delete c;

	delete instance;
	instance = nullptr;
}

CentiBodyPool * CentiBodyPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyPool;

	return instance;
}
