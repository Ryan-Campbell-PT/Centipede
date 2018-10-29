#include "FleaPool.h"
#include "Flea.h"

FleaPool* FleaPool::instance = nullptr;

FleaPool::FleaPool()
{

}

FleaPool::~FleaPool()
{
	for(auto f : this->fleaList)
		delete f;

	delete instance;
}

Flea * FleaPool::GetFlea()
{
	Flea* flea;

	if (GetInstance()->fleaList.empty())
	{
		flea = new Flea;
		flea->SetExternalManagement(RecycleFlea);
	}

	else
	{
		flea = GetInstance()->fleaList.front();
		GetInstance()->fleaList.pop_front();
		flea->RegisterToCurrentScene();
	}

	return flea;
}

void FleaPool::RecycleFlea(GameObject * flea)
{
	GetInstance()->fleaList.push_back(static_cast<Flea*>(flea));

}

FleaPool * FleaPool::GetInstance()
{
	if (instance == nullptr)
		instance = new FleaPool;

	return instance;
}
