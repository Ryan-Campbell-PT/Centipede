#include "Mushroom.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "ScoreCmd.h"

Mushroom::Mushroom(sf::Vector2f v)
{
	//Mushroom(); //this is just to run all the info in the default

	this->InitializeMushroom(v, MushroomState::Healthy);
}

Mushroom::Mushroom()
{
	//handle collision and sprite management first
	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); //4 and 2 show the first mushroom, undamaged
	SetCollider(sprite, bitmap, true);
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	//then handle positioning and housekeeping
	
	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Mushroom::Destroy()
{
	MushroomManager::RemoveMushroom(this);
	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::Collision(Scorpion*)
{	
	if (this->GetState() == MushroomState::Healthy)
		this->SetState(MushroomState::Poison);
}

void Mushroom::Collision(Bullet*)
{
	this->TakeDamage();
}

void Mushroom::InitializeMushroom(sf::Vector2f const & pos, MushroomState state)
{
	this->sprite.setPosition(pos);
	position = pos;

	this->health = 0; //setting the positions of a mushroom assumes its full health
	this->SetState(state);
	RegisterCollision<Mushroom>(*this);
}

void Mushroom::InitializeMushroom()
{
	RegisterToCurrentScene(); //todo may break things, also make sure this function works
	this->sprite.setPosition(this->position);
	RegisterCollision<Mushroom>(*this);
}

void Mushroom::TakeDamage()
{
	//progress the health of the mushroom, while also moving the animation one forward
	this->sprite.SetAnimation(health, ++health);
	
	if (health % 4 == 0) //modulous to compensate for poison or healthy
	{
		this->sprite.setScale(0.f, 0.f); //this is to avoid the 1 frame glitch
		ScoreManager::SendScoreCmd(this->pDeath); //only send score death when shot, not just destroyed
		this->MarkForDestroy();
	}

	//this->MainSprite.SetAnimation(1, 2); //second mushroom state
	//this->MainSprite.SetAnimation(2, 3); //third mushroom state
	//this->MainSprite.SetAnimation(3, 4); //fourth mushroom state
}

void Mushroom::SetState(MushroomState state)
{
	this->state = state;

	if (state == MushroomState::Poison)
	{
		this->health += 4; //+= incase the mushroom is damaged
		delete this->pDeath;
		this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomPoisonKilled);
	}

	else if (state == MushroomState::Healthy) //will likely never be called, but just to be sure
		this->health = 0; //-= incase the mushroom is damaged

	this->sprite.SetAnimation(health, health);
}

int Mushroom::DamageLevel() const
{
	return this->health;
}

void Mushroom::HealSelf()
{
	this->health = 0; //set to full health
	this->sprite.SetAnimation(health, health);
}

Mushroom::~Mushroom()
{
	delete this->pDeath;
}

sf::Vector2f Mushroom::GetPosition() const
{
	return this->position;
}

MushroomState Mushroom::GetState() const
{
	return this->state;
}
