#ifndef MUSHROOMF_H
#define MUSHROOMF_H

#include <vector>
#include <iostream>
using namespace std;

#include "Factory.h"

class Mushroom;

//this class will keep track of all mushrooms on screen and control whether they should be created
class MushroomFactory : public Factory
{
public:
	friend class Mushroom;

	virtual ~MushroomFactory(); //be sure to delete all mushrooms on screen
	
	static MushroomFactory *getInstance();

	//will confirm whether a mushroom can be placed in that area
	//returns a bool to confirm whether the mushroom was placed
	bool spawnMushroom(int posX, int posY);
		

private:
	MushroomFactory();
	static void RecycleMushroom(Mushroom *shroom);

	static MushroomFactory* instance;
	int mushroomCount; //this may be able to be replaced with getting whatever list.size()
	//somewhere here will have to keep track of all the mushrooms on screen

	std::vector<Mushroom> mushroomList;

};

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

#endif //MUSHROOMF_H