#include "Spider.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "Ship.h"
#include "SpiderManager.h"
#include "SpiderStates.h"

#include <random>
#include "ScoreManager.h"
#include "MovementCollection.h"

//TODO: turn gameobjects functions into the Destory() and Initalize() GO objects
Spider::Spider()
{
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.SetAnimation(0, 7);
	this->sprite.setScale(0.f, 0.f);

	SetCollider(sprite, bitmap, true);

	this->active = false;

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
}

void Spider::Update()
{
	if (!active)
		return;

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

	this->sprite.setPosition(this->position);
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Spider::SpawnSpider(const sf::Vector2f pos)
{
	this->position = pos;
	this->sprite.setPosition(pos);

	this->active = true;
	this->counterNum = rand() % RANDOM_CHANGE_NUM;
	this->boundsTopY = static_cast<int>(pos.y - Y_BOUNDS);
	this->boundsBottomY = static_cast<int>(pos.y + Y_BOUNDS);

	if (pos.x == 0)
		this->spiderState = &Spider_MoveFSM::diagonalDownRight;
	else
		this->spiderState = &Spider_MoveFSM::diagonalDownLeft;

	this->sprite.setScale(1.4f, 1.4f);
	RegisterCollision<Spider>(*this);
}

void Spider::Collision(Bullet *bullet)
{
	bullet->RemoveBullet();
	RemoveSpider();
	ScoreManager::SendScoreCmd(this->pDeath);
}

void Spider::Collision(Mushroom *shroom)
{
	this->spiderState = this->spiderState->GetNextState();

	shroom->RemoveMushroom();
}

void Spider::Collision(Ship * ship)
{
	ship->DestroyShip();
}

void Spider::RemoveSpider()
{
	this->active = false;
	this->DeregisterCollision<Spider>(*this);
	this->sprite.setScale(0.f, 0.f);

	SpiderManager::RemoveSpider(this);
}
