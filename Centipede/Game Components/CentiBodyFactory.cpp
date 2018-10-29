#include "CentiBodyFactory.h"
#include "CentiBodyPool.h"

CentiBodyFactory * CentiBodyFactory::instance = nullptr;

CentipedeBody * CentiBodyFactory::GetCentiBody()
{
	return CentiBodyPool::GetCentiBody();
}

CentiBodyFactory * CentiBodyFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyFactory;

	return instance;
}
