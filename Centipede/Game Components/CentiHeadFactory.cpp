#include "CentiHeadFactory.h"
#include "CentiHeadPool.h"

CentiHeadFactory * CentiHeadFactory::instance = 0;

CentipedeHead * CentiHeadFactory::GetCentiHead()
{
	return CentiHeadPool::GetCentiHead();
}

void CentiHeadFactory::RemoveCentiHead(CentipedeHead * const head)
{
	CentiHeadPool::RecycleCentiBody(head);
}

void CentiHeadFactory::EndWave()
{
	CentiHeadPool::EndWave();
}

CentiHeadFactory * CentiHeadFactory::GetInstance()
{
	if (instance == 0)
		instance = new CentiHeadFactory;

	return instance;
}
