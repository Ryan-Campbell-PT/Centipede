#include "MushroomFactory.h"
#include "Mushroom.h"


MushroomFactory::MushroomFactory()
	:mushroomCount(0)
{
}

void MushroomFactory::RecycleMushroom(Mushroom * shroom)
{
	
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
