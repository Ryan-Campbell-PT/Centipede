#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/CommonElements.h"

class Bullet;

class Mushroom : public GameObject
{
public:
	friend class MushroomFactory;

	bool SetPosition(sf::Vector2f v);
	Mushroom(sf::Vector2f v);

	virtual void Update();
	virtual void Draw();

	virtual void Collision(GameObject *g) {};
	virtual void Collision(Bullet *b);

private:
	~Mushroom();
	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

};

#endif //MUSHROOM_H