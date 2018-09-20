#include "CentiMovement.h"

CentiMoveDown::CentiMoveDown(CentipedeHead * centi)
	:centipede(centi) 
{
}

void CentiMoveDown::MoveDirection(sf::Vector2f &pos)
{
	pos.y += 3;
}

void CentiMoveDown::NextState()
{
}

//CentiMoveDown::~CentiMoveDown()
//{
//}
