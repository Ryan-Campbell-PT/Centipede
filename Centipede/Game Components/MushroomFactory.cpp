
#include "MushroomFactory.h"
#include "Mushroom.h"
#include "GameGrid.h"
#include "Observer.h"
#include "MushroomPool.h"

#include <random>

MushroomFactory * MushroomFactory::instance = nullptr; 

void MushroomFactory::RepairMushrooms()
{
	auto list = MushroomPool::GetActiveMushroomList();

	for(auto shroom : list)
		if(shroom->DamageLevel() > 0)
			shroom->HealSelf();
}

Mushroom *MushroomFactory::GetMushroom()
{
	return MushroomPool::GetMushroom();
}

void MushroomFactory::Terminate()
{
	delete instance;
	instance = nullptr;

	MushroomPool::Terminate();
}

std::list<Mushroom*>* MushroomFactory::GetCurrentLayout()
{
	return MushroomPool::GetCurrentLayout();
}

MushroomFactory * MushroomFactory::GetInstance()
{
	if (MushroomFactory::instance == nullptr)
		MushroomFactory::instance = new MushroomFactory;

	return MushroomFactory::instance;
}