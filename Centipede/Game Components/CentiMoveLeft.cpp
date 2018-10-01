#include "CentiMovement.h"

CentiMoveLeft::CentiMoveLeft()
{
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= CENTI_SPEED;

	if(static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centipede->CheckGridAhead(sf::Vector2f(pos.x - SPRITE_SIZE, pos.y));
}

void CentiMoveLeft::NextState()
{
#if WORKING
	if (prevState == CentiMovementDirectionEnum::Up)
		this->centipede->SetDirection(CentiMovementDirectionEnum::Up);
	else
		this->centipede->SetDirection(CentiMovementDirectionEnum::Down);

	this->centipede->SetAnimationFrames(SPRITE_TURN_BEGIN, SPRITE_TURN_END);

#else

	if (prevState == CentiMovementDirectionEnum::Up)
	{
		auto direction = static_cast<CentiMoveUp*>(this->centipede->GetDirection(CentiMovementDirectionEnum::Up));
		direction->Initialize(this->centipede);
		this->centipede->SetDirection(direction);
	}

	else
	{
		auto direction = static_cast<CentiMoveDown*>(this->centipede->GetDirection(CentiMovementDirectionEnum::Down));
		direction->Initialize(this->centipede);
		this->centipede->SetDirection(direction);
	}

#endif
}

void CentiMoveLeft::Initialize(CentipedeHead * centi, sf::Vector2f & pos)
{
	this->Initialize(centi);

	GameGrid::GetCenterYPosition(pos);
}

CentiMovementDirectionEnum CentiMoveLeft::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Left;
}

void CentiMoveLeft::Initialize(CentipedeHead * centi)
{
	this->centipede = centi;
	this->centipede->SetAnimationFrames(SPRITE_BEGIN, SPRITE_END);
	this->prevState = this->centipede->GetCurrentMovementDirection();
	this->centipede->SetSpriteRotation(0.f);
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}
