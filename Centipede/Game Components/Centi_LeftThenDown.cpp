#include "Centi_LeftThenDown.h"
#include "CentipedeHead.h"

Centi_LeftThenDown::Centi_LeftThenDown()
{
}

void Centi_LeftThenDown::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.x -= CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));

}

const CentipedeDirectionState * Centi_LeftThenDown::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(270.f);
	return &MoveSFM::downThenRight;
}

void Centi_LeftThenDown::Initialize(CentipedeHead * centi) const
{
	
}
