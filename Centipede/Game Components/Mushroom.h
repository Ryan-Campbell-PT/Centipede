#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/CommonElements.h"

class MushroomFactory;
class MushroomState;

class Mushroom : public GameObject
{
public:
	friend class MushroomFactory;

	///since MushroomFactory spawns the mushrooms, and checks if they can go there, no need to return anything
	void SetPosition(sf::Vector2f v);
	///using the float version means youre going to specify where its being placed pixel wise
	Mushroom(sf::Vector2f v); 
	Mushroom(float x, float y); ///this is strictly for testing purposes

	virtual void Draw();

	void TakeDamage();
	void ChangeState(MushroomState *state);
	
	MushroomState *GetState() { return this->state; } //this will be used for the centipede

private:
	virtual ~Mushroom();
	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	int health;
	MushroomState *state;
};

#endif //MUSHROOM_H