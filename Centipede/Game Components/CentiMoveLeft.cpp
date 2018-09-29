#include "CentiMovement.h"

CentiMoveLeft::CentiMoveLeft(CentipedeHead * centi)
	:centipede(centi)
{
	this->centipede->SetAnimationFrames(SPRITE_BEGIN, SPRITE_END);
	this->prevState = this->centipede->GetCurrentMovementDirection();
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= CENTI_MOVEMENT;

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));
}

void CentiMoveLeft::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Up)
		this->centipede->SetDirection(new CentiMoveUp(this->centipede));
	else
		this->centipede->SetDirection(new CentiMoveDown(this->centipede));

	this->centipede->SetAnimationFrames(SPRITE_TURN_BEGIN, SPRITE_TURN_END);
}

CentiMovementDirectionEnum CentiMoveLeft::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Left;
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}
