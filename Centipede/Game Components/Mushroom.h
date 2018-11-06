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
	explicit Mushroom(sf::Vector2f v);
	Mushroom();

	virtual void Draw() override;
	virtual void Destroy() override;

	///this inititialize handles that the mushroom is currently being set somewhere it wasnt before
	void InitializeMushroom(sf::Vector2f const & pos, MushroomState state = MushroomState::Healthy);
	///while this initialize assumes you dont care where it was before, just put it on screen
	void InitializeMushroom();
	void TakeDamage();

	sf::Vector2f GetPosition() const;
	MushroomState GetState() const; //this will be used for the centipede
	void SetState(MushroomState state);
	int DamageLevel() const;

	void HealSelf();

	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

	virtual ~Mushroom();

private:

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