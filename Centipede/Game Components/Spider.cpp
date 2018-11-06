#include "Spider.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "Ship.h"
#include "SpiderManager.h"
#include "SpiderStates.h"

#include <random>
#include "ScoreManager.h"
#include "MovementCollection.h"
//#include "SoundCmd.h"

Spider::Spider()
{
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.SetAnimation(0, 7);
	this->sprite.setScale(1.4f, 1.4f);

	SetCollider(sprite, bitmap, true);

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
	this->spawnSound = SoundManager::GetSound(SoundManager::SoundEvent::SpiderSpawn);
}

Spider::~Spider()
{
	delete pDeath;
}

void Spider::Update()
{
	this->position.y += this->spiderState->GetOffsetArray().rowoffset * SPEED;
	this->position.x += this->spiderState->GetOffsetArray().coloffset * SPEED;

	if (this->position.y <= this->boundsTopY) //bounce down if too high
		this->spiderState = this->spiderState->GetNextState();

	else if (this->position.y >= this->boundsBottomY) //bounce back up if on the bottom
		this->spiderState = this->spiderState->GetNextState();

	if(++counterNum > RANDOM_CHANGE_NUM)
	{//this adds randomization, so we assign a random value and change from diagonal/vertical mode using GetExtraState()
		
		this->spiderState = this->spiderState->GetExtraState();
		this->counterNum = rand() % RANDOM_CHANGE_NUM;
	}

	if(this->position.x > WindowManager::MainWindow.getSize().x || 
		this->position.x < 0)
	{
		this->MarkForDestroy();
		SpiderManager::SetTimer();
	}

	this->sprite.setPosition(this->position);
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Spider::Destroy()
{
	this->DeregisterCollision<Spider>(*this);
}

void Spider::SpawnSpider(const sf::Vector2f pos, const float spiderSpeed)
{
	this->position = pos;
	this->sprite.setPosition(pos);

	this->SPEED = spiderSpeed;
	this->counterNum = rand() % RANDOM_CHANGE_NUM;
	this->boundsTopY = static_cast<int>(pos.y - Y_BOUNDS);
	this->boundsBottomY = static_cast<int>(pos.y + Y_BOUNDS);

	if (pos.x == 0)
		this->spiderState = &Spider_MoveFSM::diagonalDownRight;
	else
		this->spiderState = &Spider_MoveFSM::diagonalDownLeft;

	SoundManager::SendSoundCommand(this->spawnSound);
	RegisterCollision<Spider>(*this);
}

void Spider::Collision(Bullet *bullet)
{
	bullet->MarkForDestroy();
	SpiderManager::RemoveSpider(this);
	ScoreManager::SendScoreCmd(this->pDeath);
	this->MarkForDestroy();
}

void Spider::Collision(Mushroom *shroom)
{
	this->spiderState = this->spiderState->GetNextState();

	shroom->MarkForDestroy();
}

void Spider::Collision(Ship * ship)
{
	ship->MarkForDestroy();
}