#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"
#include "MoveFSM.h"
#include "CentipedeBody.h"

#include <list>

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:bodies(0), position(pos), currentDirectionState(0), animationCounter(0), BSCounter(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	//this->SetupStates();

	//auto f = static_cast<CentiMoveLeft*>(this->GetDirection(CentiMovementDirectionEnum::Left));
	//this->SetDirection(f);
	//f->Initialize(this, this->position);
	SetupBodies();

	SetDirection(&MoveSFM::leftThenDown, false);
	
}

void CentipedeHead::Update()
{
	++animationCounter;
	auto tmpPos = this->position;

	this->currentDirectionState->MoveDirection(this, this->position);
	this->sprite.setPosition(this->position);
	//++this->BSCounter;
	//this->bodies->UpdateBody(this->position.x - tmpPos.x, this->position.y - tmpPos.y);

	if (this->animationCounter % 3 == 0)
		this->sprite.NextFrame();
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

sf::Vector2f CentipedeHead::GetPosition()
{
	return this->position;
}

void CentipedeHead::SetAnimationFrames(const int & startFrame, const int & endFrame)
{
	this->sprite.SetAnimation(startFrame, endFrame);
}

CentiMovementDirectionEnum CentipedeHead::GetCurrentMovementDirection()
{
//	if (this->currentDirectionState)
//		return this->currentDirectionState->GetDirectionEnum();
	return CentiMovementDirectionEnum::Error;
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//if we are reaching the end of the window,or see a shroom, switch to next state
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom ||
		pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.x < 0.f)
		this->SetDirection(this->currentDirectionState->NextState(this), false);

	//if we are at the tops of the window, swap to up or down
	else if (pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y))
		this->SetDirection(&MoveSFM::upThenLeft, true);

	else if (pos.y < 0.f)
		this->SetDirection(&MoveSFM::downThenLeft, true);

}

void CentipedeHead::SetDirection(CentiMovementDirectionEnum direction)
{
#if WORKING
	CentipedeDirectionState *f;
	switch (direction)
	{
	case CentiMovementDirectionEnum::Up:
		f = directionArray[static_cast<int>(CentiMovementDirectionEnum::Up)];
		f->Initialize(this);
		break;

	case CentiMovementDirectionEnum::Down:
		f = directionArray[static_cast<int>(CentiMovementDirectionEnum::Down)];
		f->Initialize(this);
		break;

	case CentiMovementDirectionEnum::Left:
		f = directionArray[static_cast<int>(CentiMovementDirectionEnum::Left)];
		static_cast<CentiMoveLeft*>(f)->Initialize(this, this->position);
		break;

	case CentiMovementDirectionEnum::Right:
		f = directionArray[static_cast<int>(CentiMovementDirectionEnum::Right)];
		static_cast<CentiMoveRight*>(f)->Initialize(this, this->position);
		break;
	}

	this->currentDirectionState = f;
#endif
}

void CentipedeHead::SetDirection(const CentipedeDirectionState * direction, bool centerToYPos)
{
	if (annoying == 1)
		this->bodies->currentOffset = this->position;
	annoying++;
	direction->Initialize(this);
	this->currentDirectionState = direction;
	if(centerToYPos)
		GameGrid::GetCenterYPosition(this->position);
	if (annoying != 1)
	{
		BSCounter++;
		this->bodies->AddOffset(this->position, this->GetOffsetConvert(this->currentDirectionState));
	}
}

void CentipedeHead::SetSpriteRotation(const float & rotation)
{
	this->sprite.setRotation(rotation);
}

CentipedeDirectionState * CentipedeHead::GetDirection(CentiMovementDirectionEnum direction)
{
	if (static_cast<int>(direction) >= 0 && static_cast<int>(direction) < DIRECTION_SIZE)
		return this->directionArray[static_cast<int>(direction)];
	else
		return nullptr;
}

void CentipedeHead::SetupStates()
{
/*	directionArray.reserve(DIRECTION_SIZE);

	directionArray.push_back(new CentiMoveLeft);
	directionArray.push_back(new CentiMoveRight);
	directionArray.push_back(new CentiMoveDown);
	directionArray.push_back(new CentiMoveUp);*/
}

void CentipedeHead::SetupBodies()
{
	this->bodies = new CentipedeBody(this);
}

BodyDir CentipedeHead::GetOffsetConvert(const CentipedeDirectionState * const offset)
{
	BodyDir d;

	switch (BSCounter % 3)
	{
	case 0:
		d = BodyDir::left;
		break;

	case 1:
		d = BodyDir::down;
		break;

	case 2:
		d = BodyDir::right;
		break;

	//case 3:
	//	d = BodyDir::left;
	//	break;

	}

	return d;
}
