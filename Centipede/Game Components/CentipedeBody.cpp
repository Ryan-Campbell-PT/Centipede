#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"

CentipedeBody::CentipedeBody(CentipedeHead * const head)
	:head(head), next(0), prev(0), currentDirection(CentiMovementDirectionEnum::Error), currentOffset(sf::Vector2f(-1, -1))
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(0, 4);

	this->position.x = head->GetPosition().x + SPRITE_SIZE;
	this->position.y = head->GetPosition().y;

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(this->position);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeBody>(*this);
	
	

}

CentipedeBody::CentipedeBody(CentipedeHead * const head, sf::Vector2f const &spawn, CentiMovementDirectionEnum direction)
	:head(head), prev(0), next(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(0, 4);

	this->position.x = head->GetPosition().x + SPRITE_SIZE;
	this->position.y = head->GetPosition().y;

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(this->position);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeBody>(*this);

	

	this->position = spawn;
	this->currentDirection = direction;

}

CentipedeBody::~CentipedeBody()
{
}

void CentipedeBody::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeBody::Update()
{
	switch (this->currentDirection)
	{
	case CentiMovementDirectionEnum::Left:
		this->position.x -= CENTI_SPEED;
		break;

	case CentiMovementDirectionEnum::Right:
		this->position.x += CENTI_SPEED;
		break;

	case CentiMovementDirectionEnum::Up:
		this->position.y -= CENTI_SPEED;
		break;

	case CentiMovementDirectionEnum::Down:
		this->position.y += CENTI_SPEED;
		break;
	}

	if (this->position == aheadTurningInformation.turningPoint)
		this->ChangePos();

	this->sprite.setPosition(this->position);
}

void CentipedeBody::ChangePos()
{
	this->offsetQueue.pop(); //pop the one youre currently using, off

	this->currentDirection = this->aheadTurningInformation.direction;

	if (this->offsetQueue.size() > 0) //but if the centi added more, continue onto that one
		this->aheadTurningInformation = this->offsetQueue.front();
}

void CentipedeBody::UpdateBody(const float & x, const float & y)
{
	this->position.x += x;
	this->position.y += y;
	this->sprite.setPosition(this->position);
}

void CentipedeBody::AddOffset(sf::Vector2f const & offset, CentiMovementDirectionEnum direction)
{
	AheadInformation f(offset, direction);
	
	if (this->offsetQueue.size() == 0)
		this->aheadTurningInformation = f;
	
	this->offsetQueue.push(f);
}