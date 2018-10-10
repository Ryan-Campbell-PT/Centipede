#include "Centi_DownThenLeft.h"
#include "CentipedeHead.h"

void Centi_DownThenLeft::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.y += CENTI_SPEED;

	if (static_cast<int>(pos.y) % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));

	/*
	if (static_cast<int>(pos.y) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x, pos.y + SPRITE_SIZE));
		*/
}

const CentipedeDirectionState * Centi_DownThenLeft::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(0.f);
	centi->CenterOnY();
	return &MoveSFM::leftThenDown;
}

CentiMovementDirectionEnum Centi_DownThenLeft::GetDirectionEnum() const
{
	return CentiMovementDirectionEnum::Down;
}
