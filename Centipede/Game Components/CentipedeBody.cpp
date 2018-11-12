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
	:animationCounter(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiBody");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiBody"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);

	SetCollider(this->sprite, this->bitmap, true);

	this->SetWhosFollowingYou(nullptr);
	this->SetWhoYoureFollowing(nullptr);
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiBodyKilled);
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
	if (this->GetWhosFollowingYou())
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->currentOffsetArray);

	this->currentOffsetArray = offset;
}

void CentipedeBody::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeBody::Update()
{
	this->position.x += this->currentOffsetArray.coloffset * CENTI_SPEED;
	this->position.y += this->currentOffsetArray.rowoffset * CENTI_SPEED;

	this->sprite.setPosition(this->position);
	
	if (++animationCounter % 3 == 0)
		sprite.NextFrame();
}

void CentipedeBody::Collision(Bullet *)
{
	MushroomManager::AttemptSpawnShroom(this->position);
	CentiBodyManager::SetBodyToHead(static_cast<CentipedeBody*>(this->GetWhosFollowingYou())); //incase this body is in the middle of the centipede
	ScoreManager::SendScoreCmd(this->pDeath);
	this->MarkForDestroy();
}

void CentipedeBody::Destroy()
{
	DeregisterCollision <CentipedeBody>(*this);
}

sf::Vector2f CentipedeBody::GetPosition() const
{
	return this->position;
}