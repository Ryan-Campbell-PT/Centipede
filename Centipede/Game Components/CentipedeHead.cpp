#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"

CentipedeHead::CentipedeHead(const sf::Vector2f & pos)
	:bodys(0), position(pos), currentDirectionState(0)
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

sf::Vector2f CentipedeHead::GetPosition()
{
	return this->position;
}

CentiMovementDirectionEnum CentipedeHead::GetCurrentMovementDirection()
{
	if(this->currentDirectionState)
		 this->currentDirectionState->GetDirectionEnum();
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	auto gridStatus = GameGrid::GetInstance()->GetGridStatus(pos);

	//a lot of if statements, can fix in the future
	if (gridStatus == GameGridEnum::Mushroom)
	{
		ConsoleMsg::WriteLine("Mushroom");
		this->currentDirectionState->NextState();
	}
	if (//gridStatus == GameGridEnum::Mushroom ||
		pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y) ||
		pos.x < 0.f ||
		pos.y < 0.f)
	{
		ConsoleMsg::WriteLine("Bounds");
		this->currentDirectionState->NextState();
	}
}

void CentipedeHead::SetDirection(CentipedeDirectionState * direction)
{
	this->currentDirectionState = direction;
}
