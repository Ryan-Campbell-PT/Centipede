#include "Body_Left.h"
#include "CentiMovement.h"

void Body_Left::MoveDirection(sf::Vector2f & pos) const
{
	pos.x -= CENTI_SPEED;
}
