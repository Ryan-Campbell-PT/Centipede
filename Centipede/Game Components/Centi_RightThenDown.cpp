#include "Centi_RightThenDown.h"
#include "CentipedeHead.h"

Centi_RightThenDown::Centi_RightThenDown()
{
}

void Centi_RightThenDown::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.x += CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

const CentipedeDirectionState * Centi_RightThenDown::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(270.f);
	return &MoveSFM::downThenLeft;
}

void Centi_RightThenDown::Initialize(CentipedeHead * centi) const
{
	
}
