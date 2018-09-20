#include "CentiMovement.h"

CentiMoveLeft::CentiMoveLeft(CentipedeHead * centi)
	:centipede(centi)
{
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= 3;

	if (pos.x < 12)
		this->centipede->currentDirectionState = new CentiMoveDown(this->centipede);
}

void CentiMoveLeft::NextState()
{
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}
