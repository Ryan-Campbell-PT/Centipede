#include "BulletManager.h"
#include "BulletFactory.h"
#include "Bullet.h"
#include "Ship.h"

BulletManager* BulletManager::instance = nullptr;

BulletManager::BulletManager()
	:bulletIsActive(false)
{
	
}

bool BulletManager::AttemptSpawnBullet()
{
	if(!GetInstance()->bulletIsActive)
	{
		instance->spawnBullet();
		return true; //we sucessfully spawned the bullet
	}

	return false; //bullet is already spawned, return false
}

void BulletManager::Terminate()
{
	delete instance;
	instance = nullptr;

	BulletFactory::Terminate();
}

BulletManager * BulletManager::GetInstance()
{
	if(instance == nullptr)
		instance = new BulletManager;

	return instance;
}

void BulletManager::spawnBullet()
{
	this->bulletIsActive = true;
	auto bullet = BulletFactory::GetBullet();
	bullet->InitializeBullet(this, Ship::GetPosition());
}
