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

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x, pos.y + SPRITE_SIZE));
}

void CentiMoveDown::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Left) //go right
		this->centipede->SetDirection(new CentiMoveRight(this->centipede));

	else
		this->centipede->SetDirection(new CentiMoveLeft(this->centipede));
}

CentiMovementDirectionEnum CentiMoveDown::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Down;
}

//CentiMoveDown::~CentiMoveDown()
//{
//}
