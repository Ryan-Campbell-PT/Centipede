#include "Centi_RightThenUp.h"
#include "CentipedeHead.h"

Centi_RightThenUp::Centi_RightThenUp()
{
}

void Centi_RightThenUp::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.x += CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

const CentipedeDirectionState* Centi_RightThenUp::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(90.f);
	return &MoveSFM::upThenLeft;
}

void Centi_RightThenUp::Initialize(CentipedeHead * centi) const
{
	
}

CentiMovementDirectionEnum Centi_RightThenUp::GetDirectionEnum() const
{
	return CentiMovementDirectionEnum::Right;
}
