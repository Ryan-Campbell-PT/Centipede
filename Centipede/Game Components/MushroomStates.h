#ifndef MUSHROOMSTATES_H
#define MUSHROOMSTATES_H

#include "State.h"

class Mushroom;

class MushroomState : public State
{
protected:
	//shouldnt be able to make a generic MushroomState
	//but a child can make a MushroomState
	MushroomState() {}; 

	Mushroom *mushroom; //each state should have access to its local mushroom
};

class PoisonState : public MushroomState
{
public:
	PoisonState(Mushroom *mushroom) {};

};

class HealthyState : public MushroomState
{
public:
	HealthyState(Mushroom *mushroom) {};

};


#endif //MUSHROOMSTATES_H