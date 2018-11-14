// Bullet
// Andre Berthiaume, Aug 2012

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

//Forward declarations
class Scorpion;
class Spider;
class Flea;
class Mushroom;
class BulletFactory;
class BulletManager;

class Bullet : public GameObject
{
public:
	Bullet();
	virtual ~Bullet() = default; //nothing to delete, the manager will delete itself
	///since nothing complicated happens on the bullet side, just have a GO collision
	virtual void Collision( GameObject *) override;

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