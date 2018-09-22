// Bullet
// Andre Berthiaume, Aug 2012

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

//Forward declarations
class Mushroom;
class BulletFactory;

class Bullet : public GameObject
{
public:
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	virtual void Collision( Mushroom *other );

	//this friend decision allows for the BulletFactory to access anything private in the bullet
	friend class BulletFactory;

private:
	//since only the bullet factory will handle the spawning of bullets,
	//we have a default constructor to create a new bullet. Then, when the bullet is shot,
	//the position is determined by that shot, handled in spawnBullet in BulletFactory
	Bullet();
	
	void removeBullet(); //instead of destroying the bullet, we will just remove from scene
	void redrawBullet(sf::Vector2f pos); //instead of creating a new bullet, just set the new position

	float SPEED;
	
	sf::Vector2f Pos;
	sf::Sprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	
};

#endif _Bullet