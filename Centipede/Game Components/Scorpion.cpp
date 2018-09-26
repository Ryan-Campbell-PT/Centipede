#include "Scorpion.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "GameGrid.h"

Scorpion::Scorpion()
{
	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

	SetCollider(sprite, bitmap, true);
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
	
	this->active = true;
	this->spawnOnLeft = pos.x < SPRITE_SIZE;
	this->sprite.setScale(1, 1);

	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Collision(Bullet * bullet)
{
	RemoveScorpion();
	bullet->RemoveBullet();
}

//todo: the current collision will collide with every single posiiton change, making A TON of new PoisonState. change in future
void Scorpion::Collision(Mushroom * shroom)
{
	if(shroom->GetState() == MushroomState::Healthy)
		shroom->ChangeState(MushroomState::Poison);
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
}
