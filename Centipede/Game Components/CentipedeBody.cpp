#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"

CentipedeBody::CentipedeBody(CentipedeHead * const head)
	:head(head), next(0), prev(0)
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
	this->currentDirection = BodyDir::left;
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
	case BodyDir::left:
		this->position.x -= CENTI_SPEED;
		break;

	case BodyDir::right:
		this->position.x += CENTI_SPEED;
		break;

	case BodyDir::up:
		this->position.y -= CENTI_SPEED;
		break;

	case BodyDir::down:
		this->position.y += CENTI_SPEED;
		break;
	}


	if (this->position == this->currentOffset)
		this->ChangePos();

	this->sprite.setPosition(this->position);
}

void CentipedeBody::ChangePos()
{
	if (this->offsetQueue.size() > 0)
	{
		auto d = this->offsetQueue.front();
		this->offsetQueue.pop();

		this->currentDirection = d.direction;
		this->currentOffset = d.offset;
	}
}

void CentipedeBody::UpdateBody(const float & x, const float & y)
{
	this->position.x += x;
	this->position.y += y;
	this->sprite.setPosition(this->position);
}

void CentipedeBody::AddOffset(sf::Vector2f const & offset, BodyDir direction)
{
	BS f;
	f.direction = direction;
	f.offset = offset;
	this->offsetQueue.push(f);
}