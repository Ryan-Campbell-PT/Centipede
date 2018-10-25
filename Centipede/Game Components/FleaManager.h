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

	static void RemoveFlea(Flea *const flea);

	virtual void ObserverUpdate(int numShrooms) override;

	FleaManager(const FleaManager &s) = delete;
	FleaManager operator = (const FleaManager &) = delete;

private:
	FleaManager();
	virtual ~FleaManager() { delete instance; }
	
	void SpawnFlea();

	static FleaManager* GetInstance();

	static FleaManager *instance;

	int numShroomsToSpawn;
	bool fleaActive; ///because there can only be 1 flea active, we simply have a bool to know if it is
};

#endif //FLEA_MANAGER