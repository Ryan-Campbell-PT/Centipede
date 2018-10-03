#include "Centi_LeftThenUp.h"
#include "CentipedeHead.h"

Centi_LeftThenUp::Centi_LeftThenUp()
	:centi(0)
{
}

void Centi_LeftThenUp::MoveDirection(sf::Vector2f & pos) const
{
	pos.x -= CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centi->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));

}

const CentipedeDirectionState * Centi_LeftThenUp::NextState() const
{
	this->centi->SetSpriteRotation(90.f);
	return &MoveSFM::upThenRight;
}
