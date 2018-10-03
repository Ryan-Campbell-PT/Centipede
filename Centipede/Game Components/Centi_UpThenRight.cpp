#include "Centi_UpThenRight.h"
#include "CentipedeHead.h"

void Centi_UpThenRight::MoveDirection(sf::Vector2f & pos)
{
}

const CentipedeDirectionState * Centi_UpThenRight::NextState()
{
	this->centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenUp;
}
