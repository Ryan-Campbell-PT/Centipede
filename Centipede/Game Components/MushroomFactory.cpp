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
	instance->activeMushroomList.erase(
		std::remove(
			instance->activeMushroomList.begin(), instance->activeMushroomList.end(), shroom)
	); //overly complicated way to remove from activeList
	shroom->MainSprite.setScale(0, 0); //remove it from the screen
	shroom->DeregisterCollision(*shroom);

	GameGrid::GetInstance()->SetGridStatus(shroom->Pos, GameGridEnum::Unoccupied);
}

void MushroomFactory::SpawnMushroom(sf::Vector2f pos)
{
	Mushroom *m;

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
	//the math behind this is so: you divide the vectors position by 24 (the sprite size) and the int conversion floor()'s it.
	//once you have the grid location (the floor()'ing), you multiply it again by the sprite size (24) to get it back to
	//its grids location in game. Then add 12 to x and y to get it centered in the grid, and have them sprite distance apart.
	
	//without this function, sprites very often overlap eachother
	pos.x = static_cast<int>(pos.x / 24) * 24 + 12;
	pos.y = static_cast<int>(pos.y / 24) * 24 + 12;
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

	//for now, mushroom spawning is randomized by the given grid set in GameGrid
	for (int i = 0; i < numShrooms; ++i)
	{
		do
		{
			x = rand() % static_cast<int>(WindowManager::MainWindow.getView().getSize().x);
			y = rand() % static_cast<int>(WindowManager::MainWindow.getView().getSize().y);
		} while ((int)GameGrid::GetInstance()->GetGridStatus(sf::Vector2f(x, y)) >= static_cast<int>(GameGridEnum::Unoccupied));
		//the choice to use >= 0 is b/c when the array space is unused, its garbage data, typically -ABigNumber
		//so this tests whether its unusued, or Unoccupied

		pos.x = x;
		pos.y = y;

		instance->SpawnMushroom(pos);
	}

	return instance;
}
