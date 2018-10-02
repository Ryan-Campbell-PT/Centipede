#ifndef MUSHROOMF_H
#define MUSHROOMF_H

#include <list>

#include "Factory.h"
#include "Observee.h"
#include "TEAL/CommonElements.h"

class Mushroom;
class Observer;

///this class will keep track of all mushrooms on screen and control whether they should be created

///the MushroomFactory handles whether a Mushroom can be placed in an area. The Mushroom itself handles actually setting the grid's data
class MushroomFactory : public Factory, public Observee
{
public:
	///remove all mushrooms created by the factory, and then delete itself
	virtual ~MushroomFactory();
	
	static void InitializeMushroomField(int numShrooms);

	///spawns a new mushroom, or recycles one from the inactiveList
	static void SpawnMushroom(sf::Vector2f pos);
	
	///takes the mushroom off the screen, and adds to a recycle list
	static void RemoveMushroom(Mushroom *shroom);

	static void AddNewObserver(Observer *o);
	static void RemoveCurrentObserver(Observer * o);

private:
	MushroomFactory();

	virtual void UpdateObservees() override;

	virtual void AddObservee(Observer *o) override;
	virtual void RemoveObservee(Observer *o) override;

	static MushroomFactory* instance;

	std::list<Mushroom*> inactiveMushroomList; ///this list will be used for recycling purposes
	std::list<Mushroom*> activeMushroomList; ///this list will be used for purposes like healing broken mushrooms at new level
	std::list<Observer*> obsererList; ///keep track of all the observee's paying attention to the factory

	static MushroomFactory *GetInstance();

};


#endif //MUSHROOMF_H