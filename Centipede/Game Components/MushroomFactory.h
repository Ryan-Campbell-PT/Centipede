#ifndef MUSHROOMF_H
#define MUSHROOMF_H

#include <list>

#include "Observee.h"

class Mushroom;
class Observer;

///this class will keep track of all mushrooms on screen and control whether they should be created

///the MushroomFactory handles whether a Mushroom can be placed in an area. The Mushroom itself handles actually setting the grid's data
class MushroomFactory
{
public:
	///remove all mushrooms created by the factory, and then delete itself
	static void Terminate();

	///spawns a new mushroom, or recycles one from the inactiveList
	static Mushroom* GetMushroom();
	static std::list<Mushroom*>* GetCurrentLayout();

	///takes the mushroom off the screen, and adds to a recycle list
	static void RemoveMushroom(Mushroom *shroom);

	static void AddNewObserver(Observer *o);
	static void RemoveCurrentObserver(Observer * o);
	static void RepairMushrooms(); ///will be called on every game over to regenerate mushrooms and get points


private:
	MushroomFactory() = default;
	virtual ~MushroomFactory() = default;

	static MushroomFactory* instance;

	std::list<Observer*> obsererList; ///keep track of all the observee's paying attention to the factory

	static MushroomFactory *GetInstance();

};


#endif //MUSHROOMF_H