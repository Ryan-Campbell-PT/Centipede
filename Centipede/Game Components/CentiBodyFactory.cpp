#include "CentiBodyFactory.h"
#include "CentiBodyPool.h"

CentiBodyFactory * CentiBodyFactory::instance = nullptr;

CentipedeBody * CentiBodyFactory::GetCentiBody()
{
	return CentiBodyPool::GetCentiBody();
}

void CentiBodyFactory::Terminate()
{
	delete instance;
	instance = nullptr;

	CentiBodyPool::Terminate();
}

CentiBodyFactory * CentiBodyFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyFactory;

	return instance;
}
