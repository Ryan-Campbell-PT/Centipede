#ifndef MUSHROOMSTATES_H
#define MUSHROOMSTATES_H

#include "State.h"

class Mushroom;

class MushroomState : public State
{
private:
	MushroomState() {}; //shouldnt be able to make a generic MushroomState

	Mushroom *mushroom; //each state should have access to its local mushroom
};

class PoisonMushroom : public MushroomState
{
public:
	PoisonMushroom(Mushroom *mushroom);

};

class DamagedMushroom : public MushroomState
{
public:
	DamagedMushroom(Mushroom *mushroom);

};

class FullMushroom : public MushroomState
{
public:
	DamagedMushroom(Mushroom *mushroom);

};


#endif //MUSHROOMSTATES_H