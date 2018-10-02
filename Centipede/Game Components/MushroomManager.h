#ifndef MUSHROOM_MANAGER
#define MUSHROOM_MANAGER

#include "TEAL/CommonElements.h"

class Mushroom;

class MushroomManager
{
public:
	static void InitializeMushroomField(int numShrooms);

	static bool AttemptSpawnShroom(sf::Vector2f const &pos);
};
#endif // !MUSHROOM_MANAGER
