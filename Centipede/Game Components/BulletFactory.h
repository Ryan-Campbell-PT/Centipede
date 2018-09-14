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
	static BulletFactory *getInstance();

	//boolean to confirm whether the bullet can spawn
	static bool SpawnBullet(sf::Vector2 pos);
	static bool SpawnBullet(float posX, float posY);

	//this is used to allow the bullet to tell the factory its no longer around
	friend class Bullet;

private:
	static BulletFactory *instance;

	static bool canSpawnBullet; //static so the bullet can change it

	Bullet *bullet; //there should only ever be 1 bullet on screen, so we just leave it as a single pointer

	BulletFactory();
	~BulletFactory();
	BulletFactory &operator=(const BulletFactory &c);
	BulletFactory(const BulletFactory &c);

};

#endif //BULLETFACTORY_H