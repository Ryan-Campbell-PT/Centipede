#ifndef SCORPION_H
#define SCORPION_H

#include "TEAL/CommonElements.h"

class Bullet;
class Mushroom;

//todo: fix sprite flipping and add a better animation system
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

	///this method will be changed in teh future, but will suffice for now
	void SetSpawnSide(bool b);
private:
	void RemoveScorpion();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
	bool active;
	const int SPEED = 200;

	bool spawnOnLeft;
};

#endif //SCORPION_H