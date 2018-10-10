#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"
#include "Bullet.h"
#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"

CentipedeBody::CentipedeBody()
	:active(false)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(0, 4);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	SetCollider(this->sprite, this->bitmap, true);

	this->SetWhosFollowingYou(nullptr);
	this->SetWhoYoureFollowing(nullptr);
}

CentipedeBody::CentipedeBody(sf::Vector2f const &spawn, CentiMovementDirectionEnum direction)
	:active(false)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(0, 4);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(this->position);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeBody>(*this);

	this->position = spawn;
	this->currentDirection = direction;

}

void CentipedeBody::InitializeBody(sf::Vector2f const & pos, CentiMovementDirectionEnum direction)
{
	this->position = pos;
	this->active = true; 
	this->animationCounter = 0;

	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(this->position);
	this->currentDirection = direction;
	
	RegisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeBody::Update()
{
	if (!active)
		return;
	++animationCounter;
	/*
	//todo: turn this into a more effective state machine
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
	
	if (this->animationCounter % 3 == 0)
		sprite.NextFrame();
		*/
	this->sprite.setPosition(this->position);
}

void CentipedeBody::Collision(Bullet * const bullet)
{
	this->RemoveBodyFromScreen(true, true);
	bullet->RemoveBullet();
}

sf::Vector2f CentipedeBody::GetPosition()
{
	return this->position;
}

void CentipedeBody::RemoveBodyFromScreen()
{
	DeregisterCollision <CentipedeBody>(*this);
	this->sprite.setScale(0.f, 0.f);
	this->active = false;
}

void CentipedeBody::ChangePos()
{
	if(this->GetWhosFollowingYou()) //make sure it has a follower
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->AddOffset(this->aheadTurningInformation.turningPoint, this->aheadTurningInformation.direction);

	this->offsetQueue.pop(); //pop the one youre currently using, off

	this->currentDirection = this->aheadTurningInformation.direction;

	if (!this->offsetQueue.empty()) //but if the centi added more, continue onto that one
		this->aheadTurningInformation = this->offsetQueue.front();
}

void CentipedeBody::RemoveBodyFromScreen(const bool& setBehindHead, const bool &spawnShroom)
{
	this->RemoveBodyFromScreen();

	CentiBodyManager::RemoveCentiBody(this, setBehindHead, spawnShroom);
}

void CentipedeBody::SetBodyToHead()
{
	CentiBodyManager::MakeBodyHead(this);
}

void CentipedeBody::UpdateBody(const float & x, const float & y)
{
	this->position.x += x;
	this->position.y += y;
	this->sprite.setPosition(this->position);
}

void CentipedeBody::AddOffset(sf::Vector2f const & offset, CentiMovementDirectionEnum direction)
{
	const AheadInformation f(offset, direction);
	
	//if (this->offsetQueue.empty())
	if (this->offsetQueue.empty())
		this->aheadTurningInformation = f;
	
	this->offsetQueue.push(f);
}