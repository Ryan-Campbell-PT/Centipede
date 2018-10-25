#ifndef SCORPION_H
#define SCORPION_H

#include "TEAL/CommonElements.h"
#include "ScoreCmd.h"

#define SPRITE_REFRESH 20

class Bullet;
class Mushroom;
class Ship;
class ScoreCmd;

//todo: fix sprite flipping and add a better animation system
class Scorpion : public GameObject
{
public:
	Scorpion();
	virtual ~Scorpion();
	Scorpion &operator=(const Scorpion &c) = delete;
	Scorpion(const Scorpion &c) = delete;

	virtual void Update() override;
	virtual void Draw() override;

	void SpawnScorpion(sf::Vector2f &pos);

	virtual void Collision(GameObject *) {};
	virtual void Collision(Bullet *bullet);
	virtual void Collision(Mushroom *shroom);
	virtual void Collision(Ship *ship);

	///this method will be changed in teh future, but will suffice for now
	void SetSpawnSide(bool b);
private:
	void RemoveScorpion();
	int counter;
	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
	bool active;
	const int SPEED = 200;

	bool spawnOnLeft;
	ScoreCmd* pDeath;
};

#endif //SCORPION_H