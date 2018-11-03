#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory * BulletFactory::instance = nullptr;

void BulletFactory::RecycleBullet(GameObject* bullet)
{
	instance->recycledBullets.push_back(static_cast<Bullet*>(bullet));
}

Bullet * BulletFactory::GetBullet()
{
	Bullet *b = nullptr;

	if(GetInstance()->recycledBullets.empty())
	{
		b = new Bullet;
		b->SetExternalManagement(RecycleBullet);
	}

	else
	{
		b = instance->recycledBullets.back();
		instance->recycledBullets.pop_back();
		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}

BulletFactory * BulletFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new BulletFactory;

	return instance;
}