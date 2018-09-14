#include "BulletFactory.h"
#include "Bullet.h"

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

void BulletFactory::SpawnBullet(sf::Vector2f pos)
{
	if(canSpawnBullet)
		bullet->redrawBullet(pos);
}

//void BulletFactory::SpawnBullet(float posX, float posY)
//{
//	bullet->redrawBullet(posX, posY);
//}
