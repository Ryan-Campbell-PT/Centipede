#include "MushroomFactory.h"
#include "Mushroom.h"
#include "GameGrid.h"

#include <random>

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

MushroomFactory::MushroomFactory()
{
}

void MushroomFactory::RecycleMushroom(Mushroom * shroom)
{
	instance->inactiveMushroomList.push_back(shroom); //recycle
	shroom->MainSprite.setScale(0, 0); //remove it from the screen
	shroom->DeregisterCollision(*shroom);

	//todo: when grid is implemented, remove from grid location as well
	GameGrid::GetInstance()->SetGridStatus(shroom->Pos, GameGridEnum::Unoccupied);
}

void MushroomFactory::SpawnMushroom(sf::Vector2f pos)
{
	Mushroom *m;

	//todo: make sure to check if you can place it here
	if (inactiveMushroomList.size() == 0)
		m = new Mushroom(pos);

	else
	{
		//recycle from the list, taking from the back and using that
		m = inactiveMushroomList.back();
		inactiveMushroomList.pop_back();

		m->SetPosition(pos);
	}

	instance->activeMushroomList.push_back(m); //tell the game this mushroom is on the screen
}

void MushroomFactory::GetNewMushroomPosition(sf::Vector2f &pos)
{
	auto gridX = static_cast<int>(floor(pos.x / 24));
	auto gridY = static_cast<int>(floor(pos.y / 24));

	pos.x = gridX * 24 + 12;
	pos.y = gridY * 24 + 12;
}

MushroomFactory::~MushroomFactory()
{
	for (auto shroom : instance->inactiveMushroomList)
		delete shroom;

	for (auto shroom : instance->activeMushroomList)
		delete shroom;

	delete instance;
}

MushroomFactory * MushroomFactory::GetInstance()
{
	if (MushroomFactory::instance == 0)
		MushroomFactory::instance = new MushroomFactory;

	return MushroomFactory::instance;
}

MushroomFactory * MushroomFactory::GetInstance(int numShrooms)
{
	if (instance == 0)
		instance = new MushroomFactory;
	
	instance->inactiveMushroomList.reserve(numShrooms); //optimize for num shrooms being made

	int x, y;
	sf::Vector2f pos;

	for (int i = 0; i < numShrooms; ++i)
	{
		do
		{
			x = rand() % static_cast<int>(WindowManager::MainWindow.getView().getSize().x);
			y = rand() % static_cast<int>(WindowManager::MainWindow.getView().getSize().y);
		} while (GameGrid::GetInstance()->GetGridStatus(sf::Vector2f(x, y)) != GameGridEnum::Unoccupied); //make sure you can plant the shroom there
		
		pos.x = x;
		pos.y = y;

		instance->SpawnMushroom(pos);
	}

	return instance;
}
