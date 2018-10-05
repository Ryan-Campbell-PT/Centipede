#ifndef SCORPION_MANAGER
#define SCORPION_MANAGER

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionManager
{
public:
	static void SpawnScorpion();

	static void RemoveScorpion(Scorpion * const scorpion);

private:
	static ScorpionManager * GetInstance();

	static ScorpionManager* instance;
};

#endif // !SPIDER_MANAGER
