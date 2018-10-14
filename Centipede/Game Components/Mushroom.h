#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/CommonElements.h"

class MushroomFactory;
class ScoreCmd;
enum class MushroomState
{
	Healthy = 0,
	Poison = 1
};

class Mushroom : public GameObject
{
public:
	///using the float version means youre going to specify where its being placed pixel wise
	Mushroom(sf::Vector2f v); 
	Mushroom();

	virtual void Draw();

	///this will handle necessary code to put the mushroom on screen
	void InitializeMushroom(sf::Vector2f const & pos, MushroomState state = MushroomState::Healthy);
	void TakeDamage();
	void RemoveMushroom();

	sf::Vector2f GetPosition() const;
	MushroomState GetState() const; //this will be used for the centipede
	void SetState(MushroomState state);

private:
	virtual ~Mushroom() = default;
	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	int health;
	MushroomState state;
	ScoreCmd *pDeath;

#if TESTING
	static int mushroomNum;
	int thisMushroomNum;
#endif
};


#endif //MUSHROOM_H