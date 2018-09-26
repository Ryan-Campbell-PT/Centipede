#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory * BulletFactory::instance = 0;


BulletFactory * BulletFactory::GetInstance()
{
	if (instance == 0)
		instance = new BulletFactory;

	return instance;
}

BulletFactory::BulletFactory()
{
	bullet = new Bullet;
}

BulletFactory::~BulletFactory()
{
	delete this->bullet;
}

bool BulletFactory::AttemptSpawnBullet(sf::Vector2f pos)
{
	if (BulletFactory::CanSpawnBullet())
	{
		GetInstance()->bullet->RedrawBullet(pos);
		return true;
	}

	return false;
}

bool BulletFactory::CanSpawnBullet()
{
	return GetInstance()->canSpawnBullet;
}

void BulletFactory::ChangeBulletStatus(bool b)
{
	GetInstance()->canSpawnBullet = b;
}