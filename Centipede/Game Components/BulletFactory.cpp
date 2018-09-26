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

bool BulletFactory::SpawnBullet(sf::Vector2f pos)
{
	if (BulletFactory::canSpawnBullet)
	{
		bullet->RedrawBullet(pos);
		return true;
	}

	return false;
}

void BulletFactory::ChangeBulletStatus(bool b)
{
	canSpawnBullet = b;
}