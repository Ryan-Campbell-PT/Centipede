
#include "MushroomFactory.h"
#include "Mushroom.h"
#include "GameGrid.h"
#include "Observer.h"
#include "MushroomPool.h"

#include <random>

MushroomFactory * MushroomFactory::instance = nullptr; 

void MushroomFactory::RemoveMushroom(Mushroom * shroom)
{
	MushroomPool::RecycleMushroom(shroom);
	GetInstance()->UpdateObservees();
}

void MushroomFactory::AddNewObserver(Observer * o)
{
	GetInstance()->AddObservee(o);
}

void MushroomFactory::RemoveCurrentObserver(Observer * o)
{
	GetInstance()->RemoveObservee(o);
}

void MushroomFactory::RepairMushrooms()
{
	auto list = MushroomPool::GetActiveMushroomList();

	for(auto shroom : list)
		if(shroom->DamageLevel() > 0)
			shroom->HealSelf();
}

void MushroomFactory::UpdateObservees()
{
	for (auto o : this->obsererList)
		o->ObserverUpdate(MushroomPool::GetNumActiveShrooms());
}

void MushroomFactory::SpawnMushroom(sf::Vector2f pos)
{
	auto shroom = MushroomPool::GetMushroom();
	shroom->InitializeMushroom(pos);
}

void MushroomFactory::AddObservee(Observer * o)
{
	this->obsererList.push_back(o);
}

void MushroomFactory::RemoveObservee(Observer * o)
{
	GetInstance()->obsererList.remove(o);
}

MushroomFactory::~MushroomFactory()
{
}

MushroomFactory * MushroomFactory::GetInstance()
{
	if (MushroomFactory::instance == 0)
		MushroomFactory::instance = new MushroomFactory;

	return MushroomFactory::instance;
}