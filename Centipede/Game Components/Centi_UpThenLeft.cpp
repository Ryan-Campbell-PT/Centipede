#include "Centi_UpThenLeft.h"
#include "CentipedeHead.h"

void Centi_UpThenLeft::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.y -= CENTI_SPEED;

	if (static_cast<int>(pos.y) % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi), true);

}

const CentipedeDirectionState * Centi_UpThenLeft::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}
