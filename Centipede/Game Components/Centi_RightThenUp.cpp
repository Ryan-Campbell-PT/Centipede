#include "Centi_RightThenUp.h"
#include "CentipedeHead.h"

void Centi_RightThenUp::MoveDirection(sf::Vector2f & pos)
{
	pos.x += CENTI_SPEED;

	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centi->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

const CentipedeDirectionState* Centi_RightThenUp::NextState()
{
	//this->centi->SetDirection();
}
