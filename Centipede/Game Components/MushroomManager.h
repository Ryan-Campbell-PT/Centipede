#ifndef MUSHROOM_MANAGER
#define MUSHROOM_MANAGER

#include "TEAL/CommonElements.h"

class Mushroom;

class MushroomManager
{
public:
	static void InitializeMushroomField(int numShrooms);
	///given a position on screen, the mushroomManager will attempt to spawn a mushroom if avaliable
	static bool AttemptSpawnShroom(sf::Vector2f pos);

	static void RemoveMushroom(Mushroom * const shroom);
	///this will be used for whatever happens when the game ends
	static void EndWave();

	MushroomManager(const MushroomManager &s) = delete;
	MushroomManager operator = (const MushroomManager &) = delete;

private:
	MushroomManager() = default;
	virtual ~MushroomManager() { delete instance; }

	static MushroomManager * GetInstance();
	void SpawnMushroom(sf::Vector2f &pos) const;

	static MushroomManager* instance;
};
#endif // !MUSHROOM_MANAGER
