#include "CentiMovement.h"

CentiMoveLeft::CentiMoveLeft(CentipedeHead * centi)
	:centipede(centi)
{
	this->prevState = this->centipede->GetCurrentMovementDirection();
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= CENTI_MOVEMENT;

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));
}

void CentiMoveLeft::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Down) //go right
		this->centipede->SetDirection(new CentiMoveDown(this->centipede));
	else
		this->centipede->SetDirection(new CentiMoveUp(this->centipede));
}

CentiMovementDirectionEnum CentiMoveLeft::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Left;
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}
