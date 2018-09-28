#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:position(pos)
{
	this->currentDirectionState = new CentiMoveLeft(this);
	
	bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	//todo: clamp position to edges of screen

	SetCollider(this->sprite, this->bitmap, true);
	//RegisterCollision<CentipedeHead>(*this);

}

void CentipedeHead::Update()
{
	this->currentDirectionState->MoveDirection(this->position);
	this->sprite.setPosition(this->position);

	
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

CentiMovementDirectionEnum CentipedeHead::GetCurrentMovementDirection()
{
	return this->currentDirectionState->GetDirectionEnum();
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	auto gridStatus = GameGrid::GetInstance()->GetGridStatus(pos);

	if (gridStatus == GameGridEnum::Mushroom)
		this->currentDirectionState->NextState();
}
