#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"
#include "Bullet.h"
#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "MushroomManager.h"

CentipedeBody::CentipedeBody()
	:active(false), bodyDirection(nullptr)
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

void CentipedeBody::InitializeBody(sf::Vector2f const & pos, CentiMovementDirectionEnum direction)
{
	this->position = pos;
	this->active = true;
	this->animationCounter = 0;

	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(this->position);
	this->bodyDirection = this->GetDirectionState(direction);

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

	this->bodyDirection->MoveDirection(this->position); //move in the direction given

	//if (this->position == aheadTurningInformation.turningPoint)
		//this->ChangePos();

	if (this->animationCounter % 3 == 0)
		sprite.NextFrame();
	if(this->animationCounter % (SPRITE_SIZE / 2) == 0)
		this->TellBoiWhoSmells(this->bodyDirection);

	this->sprite.setPosition(this->position);
}

void CentipedeBody::Collision(Bullet * const bullet)
{
	MushroomManager::AttemptSpawnShroom(this->position);
	bullet->RemoveBullet();
	this->RemoveBodyFromScreen();
	CentiBodyManager::SetBehindBodyToHead(this);
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

	CentiBodyFactory::RemoveCentiBody(this);
}

void CentipedeBody::TellBoiMyName(CentiMovementDirectionEnum direction)
{
	this->currentLiar = direction;
	this->bodyDirection = this->GetDirectionState(direction);
}

void CentipedeBody::TellBoiWhoSmells(const CentiBodyDirection * direction)
{
	if(this->GetWhosFollowingYou())
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->TellBoiMyName(this->currentLiar);
}


void CentipedeBody::ChangePos()
{
#if false
	if (this->GetWhosFollowingYou()) //make sure it has a follower
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->AddOffset(this->aheadTurningInformation.turningPoint, this->aheadTurningInformation.direction);

	this->offsetQueue.pop(); //pop the one youre currently using, off

	this->bodyDirection = this->GetDirectionState(this->aheadTurningInformation.direction);

	if (!this->offsetQueue.empty()) //but if the centi added more, continue onto that one
		this->aheadTurningInformation = this->offsetQueue.front();
#elif true
	
#endif

}

const CentiBodyDirection * CentipedeBody::GetDirectionState(CentiMovementDirectionEnum e)
{
	const CentiBodyDirection *p = nullptr;

	switch (e)
	{
	case CentiMovementDirectionEnum::Left:
		p = &MoveSFM::bodyLeft;
		break;

	case CentiMovementDirectionEnum::Right:
		p = &MoveSFM::bodyRight;
		break;

	case CentiMovementDirectionEnum::Up:
		p = &MoveSFM::bodyUp;
		break;

	case CentiMovementDirectionEnum::Down:
		p = &MoveSFM::bodyDown;
		break;
	}

	return p;
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

