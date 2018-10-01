#include "CentiMovement.h"

CentiMoveRight::CentiMoveRight()
{
}

void CentiMoveRight::MoveDirection(sf::Vector2f &pos)
{
	pos.x += CENTI_MOVEMENT;
	
	if (static_cast<int>(pos.x) % (SPRITE_SIZE / 2) == 0)
		this->centipede->CheckGridAhead(sf::Vector2f(pos.x + SPRITE_SIZE, pos.y));
}

void CentiMoveRight::NextState()
{
	if (prevState == CentiMovementDirectionEnum::Up) //go right
		this->centipede->SetDirection(CentiMovementDirectionEnum::Up);
	else
		this->centipede->SetDirection(CentiMovementDirectionEnum::Down);

	this->centipede->SetAnimationFrames(SPRITE_TURN_BEGIN, SPRITE_TURN_END);
}

void CentiMoveRight::Initialize(CentipedeHead * centi, sf::Vector2f & pos)
{
	this->Initialize(centi);
	GameGrid::GetCenterYPosition(pos);
}

CentiMovementDirectionEnum CentiMoveRight::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Right;
}

void CentiMoveRight::Initialize(CentipedeHead * centi)
{
	this->centipede = centi;
	this->centipede->SetAnimationFrames(SPRITE_BEGIN, SPRITE_END);
	this->prevState = this->centipede->GetCurrentMovementDirection();
	this->centipede->SetSpriteRotation(180.f);
}

//CentiMoveRight::~CentiMoveRight()
//{
//}
