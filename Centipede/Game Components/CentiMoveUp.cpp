#include "CentiMovement.h"


CentiMoveUp::CentiMoveUp(CentipedeHead * centi)
	:centipede(centi) 
{
	//when we start moving down, we store where we were moving last,
	//then when we move states, we can move the opposite of where we were last moving
	this->prevState = this->centipede->GetCurrentMovementDirection();
	this->centipede->SetSpriteRotation(90.f);
}

void CentiMoveUp::MoveDirection(sf::Vector2f &pos)
{
	pos.y -= CENTI_MOVEMENT;
	counter += CENTI_MOVEMENT;

	if (this->counter >= SPRITE_SIZE)
		this->NextState();

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x, pos.y + SPRITE_SIZE));
}

void CentiMoveUp::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Left) //go right
		this->centipede->SetDirection(new CentiMoveRight(this->centipede));

	else
		this->centipede->SetDirection(new CentiMoveLeft(this->centipede));
}

CentiMovementDirectionEnum CentiMoveUp::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Up;
}

//CentiMoveUp::~CentiMoveUp()
//{
//}
