#ifndef FLEA_H
#define FLEA_H

#include "TEAL/CommonElements.h"
#include "FleaState.h"
#include "Observee.h"

#define FLEASTATE1 300
#define FLEASTATE2 500

class Bullet;

class Flea : public GameObject
{
public:
	Flea();
	virtual ~Flea();
	Flea &operator=(const Flea &c) = delete;
	Flea(const Flea &c) = delete;


	virtual void Update() override;
	virtual void Draw() override;
	virtual void Collision(GameObject* o) {};
	virtual void Collision(Bullet *b);

	void SpawnFlea(sf::Vector2f pos);
	void SetSpeed(const int &speed);
	void RemoveFlea();
	void SetState(FleaState *state);
	///this method will simply take the flea's position and attempt to spawn a mushroom
	void AttemptSpawnMushroom();

private:

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	int speed;

	FleaState *state;
	//this variable should be changed in the future when figuring out how to only call 
	bool active;
};

#endif //FLEA_H