#include "FleaPool.h"
#include "Flea.h"

FleaPool* FleaPool::instance = nullptr;

void FleaPool::Terminate()
{	
	for(auto f : GetInstance()->inactiveFleaList)
	{
		delete f;
		f = nullptr;
	}

	for(auto f : GetInstance()->activeFleaList)
	{
		delete f;
		f = nullptr;
	}

	delete instance;
	instance = nullptr;
}

Flea * FleaPool::GetFlea()
{
	Flea* flea;

	if (GetInstance()->inactiveFleaList.empty())
	{
		flea = new Flea;
		flea->SetExternalManagement(RecycleFlea);
	}

	else
	{
		flea = GetInstance()->inactiveFleaList.front();
		GetInstance()->inactiveFleaList.pop_front();
		flea->RegisterToCurrentScene();
	}

	instance->activeFleaList.push_back(flea);
	return flea;
}

void FleaPool::RecycleFlea(GameObject * flea)
{
	GetInstance()->activeFleaList.remove(static_cast<Flea*>(flea));
	GetInstance()->inactiveFleaList.push_back(static_cast<Flea*>(flea));
}

FleaPool * FleaPool::GetInstance()
{
	if (instance == nullptr)
		instance = new FleaPool;

	return instance;
}
