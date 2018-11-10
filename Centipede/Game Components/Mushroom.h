#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/CommonElements.h"

class Bullet;
class Scorpion;
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
	explicit Mushroom(sf::Vector2f v);
	Mushroom();
	virtual ~Mushroom();

	virtual void Draw() override;
	virtual void Destroy() override;
	virtual void Collision(GameObject*) override {}
	virtual void Collision(Scorpion *);
	virtual void Collision(Bullet*);

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


private:

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	int health;
	MushroomState state;
	ScoreCmd *pDeath;
};


#endif //MUSHROOM_H