#include "CentiHeadFactory.h"

CentiHeadFactory * CentiHeadFactory::instance = 0;

CentiHeadFactory * CentiHeadFactory::GetInstance()
{
	if (instance == 0)
		instance = new CentiHeadFactory;

	return instance;
}
