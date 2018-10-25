#ifndef SCORPION_MANAGER
#define SCORPION_MANAGER

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionManager : public GameObject
{
public:
	static void InitializeScorpion(const float timeToSpawnInSeconds);
	static void DeInitializeScorpion();

	static void RemoveScorpion(Scorpion * const scorpion);

	ScorpionManager(const ScorpionManager &s) = delete;
	ScorpionManager& operator = (const ScorpionManager &) = delete;

private:
	ScorpionManager() = default;
	virtual ~ScorpionManager() { delete instance; }

	virtual void Alarm0() override;

	void SpawnScorpion() const;

	static ScorpionManager * GetInstance();

	static ScorpionManager* instance;

	float timeToSpawn;
	bool active;
};

#endif // !SPIDER_MANAGER
