#include "Centi_UpThenLeft.h"
#include "CentipedeHead.h"

void Centi_UpThenLeft::MoveDirection(sf::Vector2f & pos)
{
}

const CentipedeDirectionState * Centi_UpThenLeft::NextState()
{
	this->centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}
