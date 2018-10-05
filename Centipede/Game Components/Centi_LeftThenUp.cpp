#include "Centi_LeftThenUp.h"
#include "CentipedeHead.h"

Centi_LeftThenUp::Centi_LeftThenUp()
{
}

void Centi_LeftThenUp::MoveDirection(CentipedeHead *centi, sf::Vector2f & pos) const
{
	pos.x -= CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		centi->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));

}

const CentipedeDirectionState * Centi_LeftThenUp::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(90.f);
	return &MoveSFM::upThenRight;
}

void Centi_LeftThenUp::Initialize(CentipedeHead * centi) const
{
}
