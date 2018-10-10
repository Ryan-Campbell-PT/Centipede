#include "Centi_UpThenRight.h"
#include "CentipedeHead.h"

void Centi_UpThenRight::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.y -= CENTI_SPEED;

	if (static_cast<int>(pos.y) % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));

}

const CentipedeDirectionState * Centi_UpThenRight::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenUp;
}

CentiMovementDirectionEnum Centi_UpThenRight::GetDirectionEnum() const
{
	return CentiMovementDirectionEnum::Up;
}
