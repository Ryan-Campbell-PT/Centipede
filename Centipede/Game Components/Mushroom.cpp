#include "Mushroom.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "ScoreCmd.h"

#if TESTING
int Mushroom::mushroomNum = 0;
#endif

Mushroom::Mushroom(sf::Vector2f v)
{
	Mushroom();

	this->InitializeMushroom(v, MushroomState::Healthy);
}

Mushroom::Mushroom()
{
	//handle collision and sprite management first
	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); //4 and 2 show the first mushroom, undamaged
	SetCollider(sprite, bitmap, true);
	RegisterCollision<Mushroom>(*this);
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	//then handle positioning and housekeeping

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);

#if TESTING
	this->thisMushroomNum = mushroomNum++;
#endif
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Mushroom::InitializeMushroom(sf::Vector2f const & pos, MushroomState state)
{
	this->sprite.setPosition(pos);
	position = pos;

	this->health = 0; //setting the positions of a mushroom assumes its full health
	this->SetState(state);

#if TESTING
	ConsoleMsg::WriteLine("Mushroom number:" + Tools::ToString(this->mushroomNum));
#endif
}

void Mushroom::TakeDamage()
{
	//progress the health of the mushroom, while also moving the animation one forward
	this->sprite.SetAnimation(health, ++health);

	if (health % 4 == 0) //modulous to compensate for poison or healthy
	{
		this->RemoveMushroom();
		ScoreManager::SendScoreCmd(this->pDeath); //only send score death when shot, not just destroyed
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

void Mushroom::RemoveMushroom()
{
	this->sprite.setScale(0.f, 0.f); //remove it from the screen
	this->DeregisterCollision(*this);

	MushroomManager::RemoveMushroom(this);
}

sf::Vector2f Mushroom::GetPosition() const
{
	return this->position;
}

MushroomState Mushroom::GetState() const
{
	return this->state;
}
