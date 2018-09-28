#include "CentiMovement.h"

CentiMoveDown::CentiMoveDown(CentipedeHead * centi)
	:centipede(centi) 
{
	//when we start moving down, we store where we were moving last,
	//then when we move states, we can move the opposite of where we were last moving
	this->prevState = this->centipede->GetCurrentMovementDirection();
}

void CentiMoveDown::MoveDirection(sf::Vector2f &pos)
{
	pos.y += CENTI_MOVEMENT;
}

void CentiMoveDown::NextState()
{
	
}

//CentiMoveDown::~CentiMoveDown()
//{
//}
