// Bullet
// Andre Berthiaume, Aug 2012

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

class Scorpion;
class Spider;
class Flea;
//Forward declarations
class Mushroom;
class BulletFactory;
class BulletManager;

class Bullet : public GameObject
{
public:
	Bullet();

	///since nothing complicated happens on the bullet side, just have a GO collision
	virtual void Collision( GameObject *) override;

	///these both are not static because if someone if going to call them, they should have access to the object
//	void RemoveBullet(); ///instead of destroying the bullet, we will just remove from scene
//	void RedrawBullet(sf::Vector2f pos); ///instead of creating a new bullet, just set the new position

	void InitializeBullet(BulletManager *manager, sf::Vector2f pos);

private:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;

	BulletManager* manager;

	float SPEED;
	
	sf::Vector2f position;
	sf::Sprite sprite;
	CollisionTools::TextureBitmap bitmap;
	
};

#endif _Bullet