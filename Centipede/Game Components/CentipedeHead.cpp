#include "CentipedeHead.h"
#include "CentiMovement.h"

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:position(pos)
{
	this->currentDirectionState = new CentiMoveLeft(this);
	
	bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 4, 2); //4 and 2 show the first mushroom, undamaged

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2, 2);
	this->sprite.setPosition(pos);

	//todo: clamp position to edges of screen

	SetCollider(this->sprite, this->bitmap, true);
	//RegisterCollision<CentipedeHead>(*this);

}

void CentipedeHead::Update()
{
	this->currentDirectionState->MoveDirection(this->position);
	this->sprite.setPosition(position);
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}
