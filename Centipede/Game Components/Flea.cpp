#include <random>

#include "Flea.h"
#include "FleaState1.h"
#include "FleaState2.h"
#include "MushroomFactory.h"
#include "GameGrid.h"

Flea::Flea()
{
	this->state = 0;

	bitmap = ResourceManager::GetTextureBitmap("Flea");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

	MushroomFactory::GetInstance()->AddObservee(this);
}

Flea::~Flea()
{
}

void Flea::Update()
{
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

void Flea::ObserverUpdate(int numShrooms)
{
	if (numShrooms < SPAWN_FLEA_NUM)
		SpawnFlea();
}

void Flea::SpawnMushroom()
{
	//todo: this is never returning correctly. Look into it
	if(static_cast<int>(GameGrid::GetInstance()->GetGridStatus(this->position)) <= static_cast<int>(GameGridEnum::Unoccupied))
		MushroomFactory::GetInstance()->SpawnMushroom(this->position);
}

void Flea::SpawnFlea()
{
	this->state = new FleaState1;
	
	//find a random location on the screen to spawn the flea (x)
	this->position = sf::Vector2f(rand() % (int)WindowManager::MainWindow.getView().getSize().x, SPRITE_SIZE);
	GameGrid::GetInstance()->GetCenterGridPosition(this->position); //set it in the middle of the grid
	this->sprite.setPosition(position);

	this->sprite.setScale(1.f, 1.f);

	SetCollider(sprite, bitmap, true);
	RegisterCollision<Flea>(*this);

}

void Flea::RemoveFlea()
{
}
