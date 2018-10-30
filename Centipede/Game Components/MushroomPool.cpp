#include "MushroomPool.h"
#include "Mushroom.h"

MushroomPool * MushroomPool::instance = nullptr;

MushroomPool::~MushroomPool()
{
	for(auto m : this->inactiveMushroomList)
		delete m;

	for(auto m : this->activeMushroomList)
		delete m;

	delete instance;
}

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
	{
		shroom = new Mushroom;
		shroom->SetExternalManagement(RecycleMushroom);
	}

	else
	{
		shroom = GetInstance()->inactiveMushroomList.front();
		GetInstance()->inactiveMushroomList.pop_front();
		shroom->RegisterToCurrentScene();
	}

	GetInstance()->activeMushroomList.push_back(shroom); //we can assume if someone is getting a shroom, its active
	return shroom;
}

void MushroomPool::RecycleMushroom(GameObject * shroom)
{
	GetInstance()->activeMushroomList.remove(static_cast<Mushroom*>(shroom));
	GetInstance()->inactiveMushroomList.push_front(static_cast<Mushroom*>(shroom));
}

size_t MushroomPool::GetNumActiveShrooms()
{
	return GetInstance()->activeMushroomList.size();
}

std::list<Mushroom*> MushroomPool::GetActiveMushroomList()
{
	return GetInstance()->activeMushroomList;
}

std::list<Mushroom*>* MushroomPool::GetCurrentLayout()
{
	return &GetInstance()->activeMushroomList;
}
