#include "Centi_LeftThenDown.h"
#include "CentipedeHead.h"

Centi_LeftThenDown::Centi_LeftThenDown()
	:centi(0)
{
}

void Centi_LeftThenDown::MoveDirection(sf::Vector2f & pos)
{
	pos.x -= CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centi->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));

}

const CentipedeDirectionState * Centi_LeftThenDown::NextState()
{
	this->centi->SetSpriteRotation(270.f);
	return &MoveSFM::downThenRight;
}
