#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "TEAL\CommonElements.h"

class Bullet;

/***
 * Due to the simplicity of the bullet, I didnt want to make a separate pool for the bullet
 */
class BulletFactory
{
public:
	static void RecycleBullet(GameObject * bullet);
	static Bullet* GetBullet();

	static void Terminate();

	BulletFactory &operator=(const BulletFactory &c) = delete;
	BulletFactory(const BulletFactory &c) = delete;

private:
	static BulletFactory *GetInstance();

	static BulletFactory *instance;

	std::list<Bullet*> recycledBullets;
	std::list<Bullet*> activeBullets;

	BulletFactory() = default;
	virtual ~BulletFactory() = default;

};

#endif //BULLETFACTORY_H