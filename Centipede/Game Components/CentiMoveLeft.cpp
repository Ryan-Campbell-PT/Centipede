#include "CentiMovement.h"

CentiMoveLeft::CentiMoveLeft(CentipedeHead * centi)
	:centipede(centi)
{
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= CENTI_MOVEMENT;

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));
}

void CentiMoveLeft::NextState()
{
	this->centipede->SetDirection(new CentiMoveDown(this->centipede));
}

CentiMovementDirectionEnum CentiMoveLeft::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Left;
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}
