#ifndef SCORPION_H
#define SCORPION_H

#include "TEAL/CommonElements.h"

class Bullet;
class Mushroom;

class Scorpion : public GameObject
{
public:
	Scorpion();
	virtual ~Scorpion() {};
	Scorpion &operator=(const Scorpion &c) = delete;
	Scorpion(const Scorpion &c) = delete;

	virtual void Update() override;
	virtual void Draw() override;

	void SpawnScorpion(sf::Vector2f &pos);

	virtual void Collision(GameObject *) {};
	virtual void Collision(Bullet *bullet);
	virtual void Collision(Mushroom *shroom);

private:
	void RemoveScorpion();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
	bool active;
	const int SPEED = 200;
};

#endif //SCORPION_H