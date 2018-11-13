#ifndef EXPLOSIONMANAGER_H
#define EXPLOSIONMANAGER_H

#include "TEAL/CommonElements.h"

/*
 * since game objects get marked for destroy after dying, i instead use an alternative
 * class that will just take in the explosion, and display the explosion where the critter died
 */
class ExplosionManager : public GameObject
{
public:
	enum class ExplosionType
	{
		PlayerDeath,
		SpiderDeath,
		CritterDeath
	};

	static void DisplayExplosion(ExplosionType type, sf::Vector2f pos);
	static void Terminate(GameObject*);

private:

	ExplosionManager();
	static ExplosionManager*instance;
	static ExplosionManager *GetInstance();

	void spiderDeath(sf::Vector2f pos);
	void playerDeath(sf::Vector2f pos);
	void critterDeath(sf::Vector2f pos);

	virtual void Draw() override;

	int counter;

	std::vector<AnimatedSprite> explosions;
	AnimatedSprite playerDeath_sprite; bool playerActive;
	AnimatedSprite spiderDeath_sprite;
	AnimatedSprite critterDeath_sprite;
};
#endif // EXPLOSIONMANAGER_H
