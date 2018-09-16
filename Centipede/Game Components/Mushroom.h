#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/CommonElements.h"

class Bullet;
class MushroomFactory;

class Mushroom : public GameObject
{
public:
	friend class MushroomFactory;

	bool SetPosition(sf::Vector2f v);
	//using the float version means youre going to specify where its being placed pixel wise
	Mushroom(sf::Vector2f v); 
	//using the int version means youre going to specify where in the grid you want the shroom
	Mushroom(sf::Vector2i v);

	virtual void Update();
	virtual void Draw();

	void TakeDamage();
	
	virtual ~Mushroom(); //this needs to be public at the moment for some reason. Not sure why

private:
	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	int health;
};

#endif //MUSHROOM_H