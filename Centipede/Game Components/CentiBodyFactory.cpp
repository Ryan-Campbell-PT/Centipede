#include "CentiBodyFactory.h"

CentiBodyFactory * CentiBodyFactory::instance = 0;

CentiBodyFactory * CentiBodyFactory::GetInstance()
{
	if (instance == 0)
		instance = new CentiBodyFactory;

	return instance;
}
