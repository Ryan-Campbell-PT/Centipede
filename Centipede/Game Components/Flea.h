#ifndef FLEA_H
#define FLEA_H

#include "TEAL/CommonElements.h"
#include "FleaState.h"
#include "Observee.h"

#define SPAWN_FLEA_NUM 29

class Flea : public GameObject, public Observee
{
public:
	Flea();
	virtual ~Flea();
	Flea &operator=(const Flea &c) = delete;
	Flea(const Flea &c) = delete;


	virtual void Update() override;
	virtual void Draw() override;


	virtual void ObserverUpdate(int numShrooms) override;

private:
	///this method will simply take the flea's position and attempt to spawn a mushroom
	void SpawnMushroom();
	void SpawnFlea();
	void RemoveFlea();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	const int SPEED = 500;

	FleaState *state;
};

#endif //FLEA_H