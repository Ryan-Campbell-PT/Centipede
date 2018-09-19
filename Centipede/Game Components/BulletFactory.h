#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H


//#include "Bullet.h"
#include "TEAL\CommonElements.h"

class Bullet;

//this class handles the creation of bullets throughout the game
//the game is set to only spawn a single bullet at a time
class BulletFactory
{
public:
	static BulletFactory *GetInstance();

	//boolean to confirm whether the bullet can spawn
	bool SpawnBullet(sf::Vector2f pos);

	//this is used to allow the bullet to tell the factory its no longer around
	friend class Bullet;

private:
	static BulletFactory *instance;
	Bullet *bullet; //there should only ever be 1 bullet on screen, so we just leave it as a single pointer
	bool canSpawnBullet;

	BulletFactory();
	~BulletFactory();
	BulletFactory &operator=(const BulletFactory &c) = delete;
	BulletFactory(const BulletFactory &c) = delete;

	void ChangeBulletStatus(bool b); //keep it private so only bullet can access it
};

#endif //BULLETFACTORY_H