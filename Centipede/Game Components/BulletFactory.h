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
	//boolean to confirm whether the bullet can spawn
	static bool AttemptSpawnBullet(sf::Vector2f pos);
	static bool CanSpawnBullet();

	static void ChangeBulletStatus(bool b);

private:
	static BulletFactory *GetInstance();
	
	static BulletFactory *instance;
	Bullet *bullet; //there should only ever be 1 bullet on screen, so we just leave it as a single pointer
	bool canSpawnBullet;

	BulletFactory();
	~BulletFactory();
	BulletFactory &operator=(const BulletFactory &c) = delete;
	BulletFactory(const BulletFactory &c) = delete;

};

#endif //BULLETFACTORY_H