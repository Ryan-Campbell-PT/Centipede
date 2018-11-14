#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory * BulletFactory::instance = nullptr;

void BulletFactory::RecycleBullet(GameObject* bullet)
{
	instance->activeBullets.remove(static_cast<Bullet*>(bullet));
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
	for(auto b : GetInstance()->activeBullets)
	{
		delete b;
		b = nullptr;
	}
	
	for(auto b : GetInstance()->recycledBullets)
	{
		delete b;
		b = nullptr;
	}
	
	delete instance;
	instance = nullptr;
}

BulletFactory * BulletFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new BulletFactory;

	return instance;
}