#include <random>

#include "Flea.h"
#include "FleaState1.h"
#include "MushroomFactory.h"
#include "Ship.h"
#include "Bullet.h"
#include "FleaPool.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "FleaManager.h"
#include "ScoreCmd.h"

//TODO: there is a lot of deleting of state in this. figure out a way to modify tht
//so there isnt much allocation and deletion
Flea::Flea()
	:state(nullptr), speed(FLEASTATE1), destroyed(false)
{
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 4, 2);
	this->SetCollider(this->sprite, this->bitmap, true);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);
	this->spawnSound = SoundManager::GetSound(SoundManager::SoundEvent::FleaSpawn);
}

Flea::~Flea()
{
	delete pDeath;
	delete state;
}

void Flea::Update()
{
	this->position.y += speed;
	this->sprite.setPosition(this->position);

	if (this->position.y > WindowManager::MainWindow.getView().getSize().y)
		this->MarkForDestroy();

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
	b->MarkForDestroy();
}

void Flea::Collision(Ship * ship)
{
	ship->DestroyShip();
}

void Flea::Destroy()
{
	this->DeregisterCollision<Flea>(*this);
	FleaManager::SetNotActive();
}

void Flea::SpawnFlea(sf::Vector2f pos)
{
	this->position = pos;
	this->sprite.setPosition(pos);

	this->RegisterCollision<Flea>(*this);

	this->state = new FleaState1;
	this->speed = FLEASTATE1;
	SoundManager::SendSoundCommand(this->spawnSound);
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
	if(this->destroyed) //make sure the flea was actually shot, not just exceeded window size
	{
		ScoreManager::SendScoreCmd(this->pDeath);
		this->MarkForDestroy();
	}

	//delete this->state; //todo: this should be a fsm
}

void Flea::SetState(FleaState * state)
{
	delete this->state;
	this->state = state;
}
