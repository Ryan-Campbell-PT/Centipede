#ifndef SCORPION_MANAGER
#define SCORPION_MANAGER

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionManager : public GameObject
{
public:
	static void InitializeScorpion(const float timeToSpawnInSeconds);

	static void RemoveScorpion(Scorpion * const scorpion);

private:
	virtual void Alarm0() override;

	void SpawnScorpion() const;

	static ScorpionManager * GetInstance();

	static ScorpionManager* instance;

	float timeToSpawn;
};

#endif // !SPIDER_MANAGER
