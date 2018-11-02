#ifndef FLEA_MANAGER
#define FLEA_MANAGER

#include "Observer.h"

class Flea;

class FleaManager : public Observer
{
public:
	static void InitializeFlea(const int numShroomsToSpawn);
	///if the flea will not be spawning, we will simply remove it from observing
	static void DeInitializeFlea();

	///this will tell the game that there isnt a flea remaining, so its able to spawn again
	static void SetNotActive();

	virtual void ObserverUpdate(int numShrooms) override;

	FleaManager(const FleaManager &s) = delete;
	FleaManager operator = (const FleaManager &) = delete;
	static void EndWave();

	static void Terminate();

private:
	FleaManager();
	virtual ~FleaManager() = default;
	
	void SpawnFlea();

	static FleaManager* GetInstance();

	static FleaManager *instance;

	int numShroomsToSpawn; ///will indicate how many shrooms have to be on screen to spawn
	bool fleaActive; ///because there can only be 1 flea active, we simply have a bool to know if it is
};

#endif //FLEA_MANAGER