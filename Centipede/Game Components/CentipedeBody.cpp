#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"
#include "Bullet.h"
#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "MushroomManager.h"
#include "ScoreManager.h"

CentipedeBody::CentipedeBody()
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(0, 4);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);

	SetCollider(this->sprite, this->bitmap, true);

	this->SetWhosFollowingYou(nullptr);
	this->SetWhoYoureFollowing(nullptr);
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiKilled);
}

void CentipedeBody::InitializeBody(sf::Vector2f const & pos, OffsetArray direction)
{
	this->position = pos;
	this->animationCounter = 0;

	this->sprite.setPosition(this->position);
	this->currentOffsetArray = direction;

	RegisterCollision<CentipedeBody>(*this);
}

CentipedeBody::~CentipedeBody()
{
	delete this->pDeath;
}

void CentipedeBody::GetDataFromFront(OffsetArray offset)
{
	this->pastOffsetArray = this->currentOffsetArray;
	this->currentOffsetArray = offset;

	if (this->GetWhosFollowingYou())
	{
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->pastOffsetArray);
	}
}

void CentipedeBody::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeBody::Update()
{
	++animationCounter;

	this->position.x += this->currentOffsetArray.coloffset * CENTI_SPEED;
	this->position.y += this->currentOffsetArray.rowoffset * CENTI_SPEED;
	
	if (this->animationCounter % 3 == 0)
		sprite.NextFrame();

	this->sprite.setPosition(this->position);
}

void CentipedeBody::Collision(Bullet * const bullet)
{
	MushroomManager::AttemptSpawnShroom(this->position);
	bullet->MarkForDestroy();
	CentiBodyManager::SetBehindBodyToHead(this);
	ScoreManager::SendScoreCmd(this->pDeath);
	this->MarkForDestroy();
}

void CentipedeBody::Destroy()
{
	DeregisterCollision <CentipedeBody>(*this);
}

sf::Vector2f CentipedeBody::GetPosition()
{
	return this->position;
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

