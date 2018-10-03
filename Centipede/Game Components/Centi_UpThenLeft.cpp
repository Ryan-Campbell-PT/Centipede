#include "Centi_UpThenLeft.h"
#include "CentipedeHead.h"

void Centi_UpThenLeft::MoveDirection(sf::Vector2f & pos) const
{
}

const CentipedeDirectionState * Centi_UpThenLeft::NextState() const
{
	this->centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}
