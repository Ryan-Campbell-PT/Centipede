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
	this->MainSprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));
	//MainSprite.SetAnimation(0, 3);
	this->MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	SetCollider(MainSprite, bitmap);
	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	//not sure if this is needed
	//MainSprite.Update();

	Pos.y -= Game::FrameTime() * SPEED; //changed from x to y

	//if we are out of the bounds of the screen
	if (Pos.y < 0)
		removeBullet();
	
	MainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>( *this );

}

void Bullet::redrawBullet(sf::Vector2f pos)
{
	//todo: this probably doesnt work as easily as that, take a look
	this->Pos = pos;
	BulletFactory::GetInstance()->ChangeBulletStatus(false);
	RegisterCollision<Bullet>(*this);
	this->MainSprite.setScale(1, 1); //reapply the regular scale for the bullet
}

void Bullet::removeBullet()
{
	BulletFactory::GetInstance()->ChangeBulletStatus(true);
	
	//todo: figure out how to remove from screen
	DeregisterCollision<Bullet>(*this);
	this->MainSprite.setScale(0, 0); //i set the scale to remove the image from the scene. May be changed later on
}

void Bullet::Collision( Mushroom *shroom )
{
	//MarkForDestroy();
	//removeBullet();
	shroom->TakeDamage();
	
	this->removeBullet();
}