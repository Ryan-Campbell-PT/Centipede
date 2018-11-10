// Bullet
// Andre Berthiaume, Aug 2012

#include "Bullet.h"
#include "BulletFactory.h"
#include "Mushroom.h"
#include "BulletManager.h"

Bullet::Bullet()
	:manager(nullptr), SPEED(10)
{
	this->bitmap = ResourceManager::GetTextureBitmap("Bullet");
	this->sprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));
	
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	SetCollider(sprite, bitmap);
}

void Bullet::Collision(GameObject*)
{
	this->MarkForDestroy();
}

void Bullet::Update()
{
	position.y -= SPEED;

	//if we are out of the bounds of the screen
	if (position.y < 0)
		this->MarkForDestroy();
	
	sprite.setPosition(position);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>( *this );
	this->manager->SetBulletInactive();
}

void Bullet::InitializeBullet(BulletManager* manager, sf::Vector2f pos)
{
	this->manager = manager;
	this->position = pos;
	RegisterCollision<Bullet>(*this);
}