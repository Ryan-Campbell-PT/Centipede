#include "MushroomFactory.h"
#include "Mushroom.h"
#include "GameGrid.h"

#include <random>

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

MushroomFactory::MushroomFactory()
	:mushroomCount(0)
{
}

void MushroomFactory::RecycleMushroom(Mushroom * shroom)
{
	GetInstance()->mushroomList.push_back(shroom); //recycle
	shroom->MainSprite.setScale(0, 0); //remove it from the screen
	shroom->DeregisterCollision(*shroom);

	//todo: when grid is implemented, remove from grid location as well
	GameGrid::GetInstance()->SetGridStatus(shroom->Pos, GameGridEnum::Unoccupied);
}

bool MushroomFactory::SpawnMushroom(sf::Vector2f pos)
{
	Mushroom *m;

	//todo: make sure to check if you can place it here
	if (mushroomList.size() == 0)
		m = new Mushroom(pos);

	else
	{
		//recycle from the list, taking from the back and using that
		m = mushroomList.back();
		mushroomList.pop_back();

		return m->SetPosition(pos);
	}



	return false;
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

MushroomFactory * MushroomFactory::GetInstance(int numShrooms)
{
	if (instance == 0)
		instance = new MushroomFactory;
	
	GetInstance()->mushroomList.reserve(numShrooms); //optimize for num shrooms being made

	int x, y;
	sf::Vector2f pos;
	
	for (int i = 0; i < numShrooms; ++i)
	{
		x = rand() % (int)WindowManager::MainWindow.getView().getSize().x;
		y = rand() % (int)WindowManager::MainWindow.getView().getSize().y;
		
		pos.x = (float)x; pos.y = (float)y;

		GetInstance()->SpawnMushroom(pos);
	}

	return instance;
}
