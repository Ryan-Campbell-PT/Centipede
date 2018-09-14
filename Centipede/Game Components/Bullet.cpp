// Bullet
// Andre Berthiaume, Aug 2012

#include "Bullet.h"
#include "BulletFactory.h"

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

	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	MainSprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));
	//MainSprite.SetAnimation(0, 3);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

}

void Bullet::Update()
{
	//not sure if this is needed
	//MainSprite.Update();

	Pos.x += Game::FrameTime() * SPEED;

	//if (Pos.x > WindowManager::MainWindow.getSize().x ) MarkForDestroy();
	if (Pos.x > WindowManager::MainWindow.getSize().x) removeBullet();
	
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
}

void Bullet::removeBullet()
{
	BulletFactory::canSpawnBullet = true;
	
	//todo: figure out how to remove from screen
	DeregisterCollision<Bullet>(*this);
}

void Bullet::Collision( Asteroid *other )
{
	//MarkForDestroy();
	removeBullet();
}