#include "Centi_DownThenLeft.h"
#include "CentipedeHead.h"

void Centi_DownThenLeft::MoveDirection(sf::Vector2f & pos)
{
}

const CentipedeDirectionState * Centi_DownThenLeft::NextState()
{
	this->centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenDown;
}
