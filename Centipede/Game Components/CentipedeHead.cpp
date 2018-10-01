#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"
#include <list>
CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:bodys(0), position(pos), currentDirectionState(0), animationCounter(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	this->SetupStates();
	this->SetDirection(CentiMovementDirectionEnum::Left);
}

void CentipedeHead::Update()
{
	++animationCounter;
	this->currentDirectionState->MoveDirection(this->position);
	this->sprite.setPosition(this->position);

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
	if (this->currentDirectionState)
		return this->currentDirectionState->GetDirectionEnum();
	return CentiMovementDirectionEnum::Error;
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//a lot of if statements, can fix in the future
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom ||
		pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y) ||
		pos.x < 0.f ||
		pos.y < 0.f)
		this->currentDirectionState->NextState();
}

void CentipedeHead::SetDirection(CentiMovementDirectionEnum direction)
{
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
}

void CentipedeHead::SetSpriteRotation(const float & rotation)
{
	this->sprite.setRotation(rotation);
}

void CentipedeHead::SetupStates()
{
	directionArray.reserve(DIRECTION_SIZE);
	
	directionArray.push_back(new CentiMoveLeft);
	directionArray.push_back(new CentiMoveRight);
	directionArray.push_back(new CentiMoveDown);
	directionArray.push_back(new CentiMoveUp);
}
