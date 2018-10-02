#include "FleaPool.h"
#include "Flea.h"

FleaPool* FleaPool::instance = 0;

FleaPool::FleaPool()
{

}

Flea * FleaPool::GetRecycledFlea()
{
	//acquire a flea from the lisit
	auto flea = GetInstance()->fleaList.back();

	if (flea != 0)
		GetInstance()->fleaList.pop_back(); //remove from list, dont want to pop nothing

	return flea; //return the flea or the nullptr
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
