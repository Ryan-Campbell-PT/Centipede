#ifndef MUSHROOMF_H
#define MUSHROOMF_H

#include <vector>

#include "Factory.h"
#include "TEAL/CommonElements.h"

class Mushroom;

///this class will keep track of all mushrooms on screen and control whether they should be created

///the MushroomFactory handles whether a Mushroom can be placed in an area. The Mushroom itself handles actually setting the grid's data
class MushroomFactory : public Factory
{
public:
	friend class Mushroom;

	///remove all mushrooms created by the factory, and then delete itself
	virtual ~MushroomFactory();
	
	static MushroomFactory *GetInstance();
	static MushroomFactory *GetInstance(int numShrooms); //todo: may wanna take an alternateive approach to this

	///spawns a new mushroom, or recycles one from the inactiveList
	void SpawnMushroom(sf::Vector2f pos);
		

private:
	MushroomFactory();
	void RecycleMushroom(Mushroom *shroom);

	static MushroomFactory* instance;

	std::vector<Mushroom*> inactiveMushroomList; ///this list will be used for recycling purposes
	std::vector<Mushroom*> activeMushroomList; ///this list will be used for purposes like healing broken mushrooms at new level
};


#endif //MUSHROOMF_H