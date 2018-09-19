#include "CentipedeHead.h"
#include "CentipedeDirectionState.h"

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:position(pos)
{
	this->currentDirectionState = new CentiMoveLeft(this);
}
