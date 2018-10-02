#ifndef FLEA_MANAGER
#define FLEA_MANAGER

#include "Observer.h"

#define SPAWN_FLEA_NUM 29

class Flea;

class FleaManager : public Observer
{
public:
	static void InitializeFlea();

	virtual void ObserverUpdate(int numShrooms) override;

private:
	void SpawnFlea();

	FleaManager();
	static FleaManager* GetInstance();

	static FleaManager *instance;
};

#endif //FLEA_MANAGER