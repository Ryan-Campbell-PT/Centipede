#include "Flea.h"
#include "FleaState1.h"
#include "FleaState2.h"

Flea::Flea()
{
	this->state = new FleaState1;
}

Flea::~Flea()
{
}
