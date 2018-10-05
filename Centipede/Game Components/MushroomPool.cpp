#include "MushroomPool.h"
#include "Mushroom.h"

MushroomPool * MushroomPool::instance = 0;

MushroomPool * MushroomPool::GetInstance()
{
	if (instance == 0)
		instance = new MushroomPool;

	return instance;
}

Mushroom * MushroomPool::GetMushroom()
{
	Mushroom* flea;

	if (GetInstance()->inactiveMushroomList.size() == 0)
		flea = new Mushroom;

	else
	{
		flea = GetInstance()->inactiveMushroomList.front();
		GetInstance()->inactiveMushroomList.pop_front();
	}

	return flea;
}

void MushroomPool::RecycleMushroom(Mushroom * shroom)
{
	GetInstance()->activeMushroomList.remove(shroom);
	GetInstance()->inactiveMushroomList.push_front(shroom);
}

size_t MushroomPool::GetNumActiveShrooms()
{
	return GetInstance()->activeMushroomList.size();
}
