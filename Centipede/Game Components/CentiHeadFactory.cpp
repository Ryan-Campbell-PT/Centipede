#include "CentiHeadFactory.h"
#include "CentiHeadPool.h"

CentiHeadFactory * CentiHeadFactory::instance = nullptr;

CentipedeHead * CentiHeadFactory::GetCentiHead()
{
	return CentiHeadPool::GetCentiHead();
}

void CentiHeadFactory::EndWave()
{
	CentiHeadPool::EndWave();
}

void CentiHeadFactory::Terminate()
{
	delete instance;
	instance = nullptr;

	CentiHeadPool::Terminate();
}

CentiHeadFactory * CentiHeadFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadFactory;

	return instance;
}
