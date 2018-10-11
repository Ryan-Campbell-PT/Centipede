#include "Body_Right.h"
#include "CentiMovement.h"

void Body_Right::MoveDirection(sf::Vector2f & pos) const
{
	pos.x += CENTI_SPEED;
}
