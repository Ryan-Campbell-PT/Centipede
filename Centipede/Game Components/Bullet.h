// Bullet
// Andre Berthiaume, Aug 2012

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

//Forward declarations
class Asteroid;
class BulletFactory;

class Bullet : public GameObject
{
public:
	void Initialize(sf::Vector2f p); 

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	virtual void Collision( Asteroid *other );


	//this friend decision allows for the BulletFactory to access anything private in the bullet
	friend class BulletFactory;

private:
	Bullet(sf::Vector2f p); //bullet factory handles bullet spawning
	void removeBullet(); //instead of destroying the bullet, we will just remove from scene


	float SPEED;
	
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	
};

#endif _Bullet