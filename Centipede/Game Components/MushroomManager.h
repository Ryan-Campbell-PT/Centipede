#ifndef MUSHROOM_MANAGER
#define MUSHROOM_MANAGER

#include "TEAL/CommonElements.h"

class Mushroom;

class MushroomManager
{
public:
	static void InitializeMushroomField(int numShrooms);

	static bool AttemptSpawnShroom(sf::Vector2f &pos);

	static void RemoveMushroom(Mushroom * const shroom);

private:
	static MushroomManager * GetInstance();
	void SpawnMushroom(sf::Vector2f &pos);

	static MushroomManager* instance;
};
#endif // !MUSHROOM_MANAGER
