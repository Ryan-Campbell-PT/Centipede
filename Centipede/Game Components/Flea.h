#ifndef FLEA_H
#define FLEA_H

#include "TEAL/CommonElements.h"
#include "FleaState.h"

class Flea : public GameObject
{
public:
	Flea();
	virtual ~Flea();
	Flea &operator=(const Flea &c) = delete;
	Flea(const Flea &c) = delete;

private:
	///this method will simply take the flea's position and attempt to spawn a mushroom
	void SpawnMushroom();

	sf::Vector2f position;
	AnimatedSprite sprite;
	const int speed = 500;

	FleaState *state;
};

#endif //FLEA_H