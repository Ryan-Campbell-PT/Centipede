#include <random>

#include "Flea.h"
#include "FleaState1.h"
#include "FleaState2.h"
#include "MushroomFactory.h"

Flea::Flea()
{
	this->state = new FleaState1;

	bitmap = ResourceManager::GetTextureBitmap("Flea");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	MushroomFactory::GetInstance()->AddObservee(this);
}

Flea::~Flea()
{
}

void Flea::Update()
{
	if (rand() % 3 == 0)
		this->SpawnMushroom();
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
	MushroomFactory::GetInstance()->SpawnMushroom(this->position);
}

void Flea::SpawnFlea()
{
	//this is false
	//this->position = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f, WindowManager::MainWindow.getView().getSize().y * .9f);
	this->sprite.setPosition(position);

	SetCollider(sprite, bitmap, true);
	RegisterCollision<Flea>(*this);

}
