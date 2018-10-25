#include "FleaPool.h"
#include "Flea.h"

FleaPool* FleaPool::instance = 0;

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

	if (GetInstance()->fleaList.size() == 0)
		flea = new Flea;

	else
	{
		flea = GetInstance()->fleaList.front();
		GetInstance()->fleaList.pop_front();
	}

	return flea;
}

void FleaPool::RecycleFlea(Flea * flea)
{
	GetInstance()->fleaList.push_back(flea);

}

FleaPool * FleaPool::GetInstance()
{
	if (instance == nullptr)
		instance = new FleaPool;

	return instance;
}
