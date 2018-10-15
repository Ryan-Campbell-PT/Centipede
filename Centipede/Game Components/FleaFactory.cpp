#include "FleaFactory.h"
#include "Flea.h"
#include "FleaPool.h"

FleaFactory * FleaFactory::instance = nullptr;

Flea * FleaFactory::GetFlea()
{
	return FleaPool::GetFlea();
}

void FleaFactory::RemoveFlea(Flea * const flea)
{
	FleaPool::RecycleFlea(flea);
}

FleaFactory * FleaFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new FleaFactory;

	return instance;
}
