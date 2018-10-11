#include "Body_Up.h"
#include "CentiMovement.h"

void Body_Up::MoveDirection(sf::Vector2f & pos) const
{
	pos.y -= CENTI_SPEED;
}
