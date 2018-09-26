// Bullet
// Andre Berthiaume, Aug 2012

#include "Bullet.h"
#include "BulletFactory.h"
#include "Mushroom.h"
#include "Ship.h"

/*
Bullet::Bullet(sf::Vector2f p)
{

	SetCollider(MainSprite, bitmap);

	Pos = p;
	RegisterCollision<Bullet>( *this );
}
*/

Bullet::Bullet()
{
	SPEED = 800;

	this->bitmap = ResourceManager::GetTextureBitmap("Bullet");
	this->sprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));
	
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	SetCollider(sprite, bitmap);
	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	//not sure if this is needed
	//MainSprite.Update();

	position.y -= Game::FrameTime() * SPEED; //changed from x to y

	//if we are out of the bounds of the screen
	if (position.y < 0)
		RemoveBullet();
	
	sprite.setPosition(position);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(sprite);
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>( *this );
}

void Bullet::RedrawBullet(sf::Vector2f pos)
{
	this->position = pos;
	BulletFactory::ChangeBulletStatus(false);
	RegisterCollision<Bullet>(*this);
	this->sprite.setScale(1, 1); //reapply the regular scale for the bullet
}

void Bullet::RemoveBullet()
{
	BulletFactory::ChangeBulletStatus(true);
	
	DeregisterCollision<Bullet>(*this);
	this->sprite.setScale(0, 0); //i set the scale to remove the image from the scene. May be changed later on
}

void Bullet::Collision( Mushroom *shroom )
{
	shroom->TakeDamage();
	
	this->RemoveBullet();
}