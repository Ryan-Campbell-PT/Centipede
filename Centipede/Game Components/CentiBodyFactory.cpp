#include "CentiBodyFactory.h"
#include "CentiBodyPool.h"

CentiBodyFactory * CentiBodyFactory::instance = 0;

CentipedeBody * CentiBodyFactory::GetCentiBody(const CentiBodyManager const * d)
{
	return CentiBodyPool::GetCentiBody();
}

void CentiBodyFactory::RemoveCentiBody(const CentiBodyManager const * d, CentipedeBody * const body)
{
	CentiBodyPool::RecycleCentiBody(body);
}

CentiBodyFactory * CentiBodyFactory::GetInstance()
{
	if (instance == 0)
		instance = new CentiBodyFactory;

	return instance;
}
