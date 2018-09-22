#include <random>

#include "Flea.h"
#include "FleaState1.h"
#include "FleaState2.h"
#include "MushroomFactory.h"
#include "GameGrid.h"

Flea::Flea()
	:state(0), active(false)
{
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

}

Flea::~Flea()
{
}

void Flea::Update()
{
	if (!active)
		return;

	this->position.y += Game::FrameTime() * SPEED;
	this->sprite.setPosition(this->position);

	//this spawning method is very ineffecient atm, will fix later
	if (rand() % 3 == 0)
		this->SpawnMushroom();

	if (this->position.y > WindowManager::MainWindow.getView().getSize().y)
		RemoveFlea();
}

void Flea::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Flea::SpawnFlea(sf::Vector2f pos)
{
	this->active = true;
	this->position = pos;
	this->sprite.setPosition(pos);

	this->sprite.setScale(1.f, 1.f);

	this->SetCollider(this->sprite, this->bitmap, true);
	this->RegisterCollision<Flea>(*this);


}

void Flea::SpawnMushroom()
{
	if(static_cast<int>(GameGrid::GetInstance()->GetGridStatus(this->position)) <= static_cast<int>(GameGridEnum::Unoccupied))
		MushroomFactory::GetInstance()->SpawnMushroom(this->position);
}


void Flea::RemoveFlea()
{
	this->active = false;
	this->DeregisterCollision<Flea>(*this);
	this->sprite.setScale(0.f, 0.f);
}
