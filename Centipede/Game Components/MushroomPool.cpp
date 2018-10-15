#include "MushroomPool.h"
#include "Mushroom.h"

MushroomPool * MushroomPool::instance = nullptr;

MushroomPool * MushroomPool::GetInstance()
{
	if (instance == nullptr)
		instance = new MushroomPool;

	return instance;
}

Mushroom * MushroomPool::GetMushroom()
{
	Mushroom* shroom;

	if (GetInstance()->inactiveMushroomList.empty())
		shroom = new Mushroom;

	else
	{
		shroom = GetInstance()->inactiveMushroomList.front();
		GetInstance()->inactiveMushroomList.pop_front();
	}

	GetInstance()->activeMushroomList.push_back(shroom); //we can assume if someone is getting a shroom, its active
	return shroom;
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
