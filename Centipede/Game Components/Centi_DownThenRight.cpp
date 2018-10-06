#include "Centi_DownThenRight.h"
#include "CentipedeHead.h"

void Centi_DownThenRight::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.y += CENTI_SPEED;
	
	if (static_cast<int>(pos.y) % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi), true);
	/*
	if (static_cast<int>(pos.y) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x, pos.y + SPRITE_SIZE));
		*/
}

const CentipedeDirectionState * Centi_DownThenRight::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenDown;
}

CentiMovementDirectionEnum Centi_DownThenRight::GetDirectionEnum() const
{
	return CentiMovementDirectionEnum::Down;
}
