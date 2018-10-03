#include "Centi_UpThenRight.h"

void Centi_UpThenRight::MoveDirection(sf::Vector2f & pos)
{
}

const CentipedeDirectionState * Centi_UpThenRight::NextState()
{
	auto f = new Centi_DownThenLeft;
	auto r = &MoveSFM::downThenLeft;
	
	
	return r;

}
