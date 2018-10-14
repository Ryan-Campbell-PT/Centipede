#include <random>

#include "Flea.h"
#include "FleaState1.h"
#include "MushroomFactory.h"
#include "Ship.h"
#include "Bullet.h"
#include "FleaPool.h"
#include "MushroomManager.h"
#include "ScoreManager.h"

//TODO: there is a lot of deleting of state in this. figure out a way to modify tht
//so there isnt much allocation and deletion
Flea::Flea()
	:state(0), active(false), speed(FLEASTATE1), destroyed(false)
{
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);
}

void Flea::Update()
{
	//this will have to be changed in the future. for now this will work
	if (!active)
		return;

	this->position.y += Game::FrameTime() * speed;
	this->sprite.setPosition(this->position);


	if (this->position.y > WindowManager::MainWindow.getView().getSize().y)
		RemoveFlea();

	else
		this->state->StateAction(this);
}

void Flea::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Flea::Collision(Bullet * b)
{
	this->state->TakeDamage(this);
	b->RemoveBullet();
}

void Flea::Collision(Ship * ship)
{
	ship->DestroyShip();
}

void Flea::SpawnFlea(sf::Vector2f pos)
{
	this->active = true;
	this->position = pos;
	this->sprite.setPosition(pos);

	this->sprite.setScale(1.f, 1.f);

	this->SetCollider(this->sprite, this->bitmap, true);
	this->RegisterCollision<Flea>(*this);

	this->state = new FleaState1;
	this->speed = FLEASTATE1;
}

void Flea::SetSpeed(const int & speed)
{
	this->speed = speed;
}

void Flea::AttemptSpawnMushroom()
{
	MushroomManager::AttemptSpawnShroom(this->position);
}

sf::Vector2f Flea::GetPosition() const
{
	return position;
}

void Flea::RemoveFlea()
{
	this->active = false;
	this->DeregisterCollision<Flea>(*this);
	this->sprite.setScale(0.f, 0.f);
	
	FleaPool::RecycleFlea(this);

	if(this->destroyed)
		ScoreManager::SendScoreCmd(this->pDeath);

	delete this->state;
}

void Flea::SetState(FleaState * state)
{
	delete this->state;
	this->state = state;
}
