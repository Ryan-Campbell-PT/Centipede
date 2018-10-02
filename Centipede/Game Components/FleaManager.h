#ifndef FLEA_MANAGER
#define FLEA_MANAGER

#include "Observee.h"

class Flea;

class FleaManager : public Observer
{
	virtual void ObserverUpdate(int numShrooms) override;

private:
	void AttemptSpawnFlea();

	FleaManager();
	static FleaManager* GetInstance();

	static FleaManager *instance;
};

#endif //FLEA_MANAGER