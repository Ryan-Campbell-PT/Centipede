#include "CentiMovement.h"

CentiMoveRight::CentiMoveRight(CentipedeHead * centi)
	:centipede(centi) 
{
	this->centipede->SetAnimationFrames(SPRITE_BEGIN, SPRITE_END);
	this->prevState = this->centipede->GetCurrentMovementDirection();
}

void CentiMoveRight::MoveDirection(sf::Vector2f &pos)
{
	pos.x += CENTI_MOVEMENT;
	
	if (static_cast<int>(pos.x) % (SPRITE_SIZE  / 2) == 0)
		this->centipede->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

void CentiMoveRight::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Up) //go right
		this->centipede->SetDirection(new CentiMoveUp(this->centipede));
	else
		this->centipede->SetDirection(new CentiMoveDown(this->centipede));

	this->centipede->SetAnimationFrames(SPRITE_TURN_BEGIN, SPRITE_TURN_END);
}

CentiMovementDirectionEnum CentiMoveRight::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Right;
}

//CentiMoveRight::~CentiMoveRight()
//{
//}
