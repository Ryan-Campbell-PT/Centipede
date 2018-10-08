#include "CentiBodyManager.h"

CentiBodyManager * CentiBodyManager::instance = 0;

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if(instance == 0)
		instance = new CentiBodyManager;

	return instance;
}
