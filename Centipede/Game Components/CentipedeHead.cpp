#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:bodys(0), position(pos), currentDirectionState(0), animationCounter(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	//todo: clamp position to edges of screen
	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	this->currentDirectionState = new CentiMoveLeft(this);
}

void CentipedeHead::Update()
{
	++animationCounter;
	this->currentDirectionState->MoveDirection(this->position);
	this->sprite.setPosition(this->position);

	if(this->animationCounter % 3 == 0)
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
	if(this->currentDirectionState)
		 return this->currentDirectionState->GetDirectionEnum();
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//a lot of if statements, can fix in the future
	if (GameGrid::GetInstance()->GetGridStatus(pos) == GameGridEnum::Mushroom ||
		pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y) ||
		pos.x < 0.f ||
		pos.y < 0.f)
		this->currentDirectionState->NextState();
}

void CentipedeHead::SetDirection(CentipedeDirectionState * direction)
{
	//delete this->currentDirectionState;
	this->currentDirectionState = direction;
}
