#include "Centi_DownThenRight.h"
#include "CentipedeHead.h"

void Centi_DownThenRight::MoveDirection(sf::Vector2f & pos)
{
}

const CentipedeDirectionState * Centi_DownThenRight::NextState()
{
	this->centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenDown;
}
