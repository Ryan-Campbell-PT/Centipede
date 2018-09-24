#include "Scorpion.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "MushroomStates.h"

Scorpion::Scorpion()
{
	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

}

void Scorpion::Update()
{
	if (!active)
		return;

	if (spawnOnLeft)
	{
		this->position.x += Game::FrameTime() * SPEED;

		if (this->position.x > WindowManager::MainWindow.getSize().x)
			RemoveScorpion();
	}

	else
	{
		this->position.x -= Game::FrameTime() * SPEED;

		if (this->position.x < 0)
			RemoveScorpion();
	}

	this->sprite.setPosition(this->position);


}

void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);

}

void Scorpion::SpawnScorpion(sf::Vector2f & pos)
{
	this->position = pos;
	this->sprite.setPosition(pos);
	this->sprite.setScale(1.f, 1.f);
	this->active = true;
	if (this->spawnOnLeft)
		this->sprite.setRotation(180.f);
	else
		this->sprite.setRotation(0.f);

	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Collision(Bullet * bullet)
{
	RemoveScorpion();
}
//todo: make collision work. not working atm
void Scorpion::Collision(Mushroom * shroom)
{
	shroom->ChangeState(new PoisonState(shroom));
}

void Scorpion::SetSpawnSide(bool b)
{
	spawnOnLeft = b;
}

void Scorpion::RemoveScorpion()
{
	this->active = false;
	this->DeregisterCollision<Scorpion>(*this);
	this->sprite.setScale(0.f, 0.f);

	DeregisterCollision<Scorpion>(*this);
}
