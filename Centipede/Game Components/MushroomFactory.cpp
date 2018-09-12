#include "MushroomFactory.h"

MushroomFactory * MushroomFactory::getInstance()
{
	if (MushroomFactory::instance == 0)
		MushroomFactory::instance = new MushroomFactory;
	
	return MushroomFactory::instance;
}