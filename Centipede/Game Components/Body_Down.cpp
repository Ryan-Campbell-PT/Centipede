#include "Body_Down.h"
#include "CentiMovement.h"

void Body_Down::MoveDirection(sf::Vector2f & pos) const
{
	pos.y += CENTI_SPEED;
}
