#include "MushroomFactory.h"


MushroomFactory::MushroomFactory()
	:mushroomCount(0)
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
