#include "Centi_RightThenUp.h"
#include "CentipedeHead.h"

Centi_RightThenUp::Centi_RightThenUp()
	:centi(0)
{
}

void Centi_RightThenUp::MoveDirection(sf::Vector2f & pos) const
{
	pos.x += CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centi->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

const CentipedeDirectionState* Centi_RightThenUp::NextState() const
{
	this->centi->SetSpriteRotation(90.f);
	return &MoveSFM::upThenLeft;
}
