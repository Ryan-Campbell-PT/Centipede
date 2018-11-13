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

	instance->activeBodyList.push_front(body);
	return body;
}

void CentiBodyPool::RecycleCentiBody(GameObject * const body)
{
	GetInstance()->activeBodyList.remove(static_cast<CentipedeBody*>(body));
	GetInstance()->inactiveBodyList.push_front(static_cast<CentipedeBody*>(body));
}

void CentiBodyPool::Terminate()
{	
	for(auto c : GetInstance()->activeBodyList)
	{
		delete c;
		c = nullptr;
	}

	for(auto c : GetInstance()->inactiveBodyList)
	{
		
		delete c;
		c = nullptr;
	}

	delete instance;
	instance = nullptr;
}

CentiBodyPool * CentiBodyPool::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyPool;

	return instance;
}
