#include "CentiMovement.h"

CentiMoveDown::CentiMoveDown()
{
}

void CentiMoveDown::MoveDirection(sf::Vector2f &pos)
{
	pos.y += CENTI_MOVEMENT;
	counter += CENTI_MOVEMENT;

	if (this->counter >= SPRITE_SIZE)
		this->NextState();

	this->centipede->CheckGridAhead(sf::Vector2f(pos.x, pos.y + SPRITE_SIZE));
}

void CentiMoveDown::NextState()
{
	if (this->centipede->GetPosition().y > static_cast<float>(WindowManager::MainWindow.getSize().y - SPRITE_SIZE))
	{
		ConsoleMsg::WriteLine("Max bottom");
		this->centipede->SetDirection(CentiMovementDirectionEnum::Up);
	}

	else if (prevState == CentiMovementDirectionEnum::Left) //go right
		this->centipede->SetDirection(CentiMovementDirectionEnum::Right);

	else
		this->centipede->SetDirection(CentiMovementDirectionEnum::Left);
}

void CentiMoveDown::Initialize(CentipedeHead * centi)
{
	//when we start moving down, we store where we were moving last,
	//then when we move states, we can move the opposite of where we were last moving
	this->centipede = centi;
	this->counter = 0;
	this->prevState = this->centipede->GetCurrentMovementDirection();
	this->centipede->SetSpriteRotation(270.f);
}

CentiMovementDirectionEnum CentiMoveDown::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Down;
}

//CentiMoveDown::~CentiMoveDown()
//{
//}
