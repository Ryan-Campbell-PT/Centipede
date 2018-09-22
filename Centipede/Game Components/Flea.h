#ifndef FLEA_H
#define FLEA_H

#include "TEAL/CommonElements.h"
#include "FleaState.h"
#include "Observee.h"


class Flea : public GameObject
{
public:
	Flea();
	virtual ~Flea();
	Flea &operator=(const Flea &c) = delete;
	Flea(const Flea &c) = delete;


	virtual void Update() override;
	virtual void Draw() override;

	void SpawnFlea(sf::Vector2f pos);

//private:
	///this method will simply take the flea's position and attempt to spawn a mushroom
	void SpawnMushroom();
	void RemoveFlea();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	const int SPEED = 500;

	FleaState *state;
	bool active;
};

#endif //FLEA_H