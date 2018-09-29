#include "CentiMovement.h"

CentiMoveRight::CentiMoveRight(CentipedeHead * centi)
	:centipede(centi) 
{
}

void CentiMoveRight::MoveDirection(sf::Vector2f &pos)
{
	pos.x += CENTI_MOVEMENT;

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

void CentiMoveRight::NextState()
{
	this->centipede->SetDirection(new CentiMoveDown(this->centipede));
}

CentiMovementDirectionEnum CentiMoveRight::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Right;
}

//CentiMoveRight::~CentiMoveRight()
//{
//}
