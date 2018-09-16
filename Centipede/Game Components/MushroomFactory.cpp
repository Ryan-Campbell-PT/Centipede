#include "MushroomFactory.h"
#include "Mushroom.h"

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

MushroomFactory::MushroomFactory()
	:mushroomCount(0)
{
}

void MushroomFactory::RecycleMushroom(Mushroom * shroom)
{
	getInstance()->mushroomList.push_back(shroom);
	shroom->MainSprite.setScale(0, 0); //remove it from the screen
	shroom->DeregisterCollision(*shroom);
	//todo: when grid is implemented, remove from grid location as well
}

MushroomFactory::~MushroomFactory()
{
}

MushroomFactory * MushroomFactory::getInstance()
{
	if (MushroomFactory::instance == 0)
		MushroomFactory::instance = new MushroomFactory;

	return MushroomFactory::instance;
}
