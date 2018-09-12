#ifndef MUSHROOMF_H
#define MUSHROOMF_H

#include "Factory.h"

//this class will keep track of all mushrooms on screen and control whether they should be created
class MushroomFactory : public Factory
{
public:
	virtual ~MushroomFactory(); //be sure to delete all mushrooms on screen
	
	static MushroomFactory *getInstance();

	//will confirm whether a mushroom can be placed in that area
	//static so any class can attempt to spawn a mushroom
	static void spawnMushroom(int posX, int posY);
		
private:
	MushroomFactory();

	static MushroomFactory* instance;
	int mushroomCount; //this may be able to be replaced with getting whatever list.size()
	//somewhere here will have to keep track of all the mushrooms on screen
};

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

#endif //MUSHROOMF_H