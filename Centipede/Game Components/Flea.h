#ifndef FLEA_H
#define FLEA_H

#include "TEAL/CommonElements.h"
#include "FleaState.h"
#include "Observee.h"

#define FLEASTATE1 2
#define FLEASTATE2 5

class Bullet;
class Ship;
class ScoreCmd;
class SoundCmd;

class Flea : public GameObject
{
public:
	Flea();
	virtual ~Flea();
	Flea &operator=(const Flea &c) = delete;
	Flea(const Flea &c) = delete;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Collision(GameObject* o) override{};
	virtual void Collision(Bullet *b);
	virtual void Collision(Ship *ship);
	virtual void Destroy() override;

	void SpawnFlea(sf::Vector2f pos);
	void SetSpeed(const int &speed);
	void RemoveFlea();
	void SetState(FleaState *state);
	///this method will simply take the flea's position and attempt to spawn a mushroom
	void AttemptSpawnMushroom();
	sf::Vector2f GetPosition() const;
	void SetDestroyed() { this->destroyed = true; }

private:

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	int speed;

	FleaState *state;
	ScoreCmd *pDeath;
	SoundCmd *spawnSound;
	bool destroyed;
};

#endif //FLEA_H