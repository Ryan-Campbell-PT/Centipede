#ifndef SCORPION_MANAGER
#define SCORPION_MANAGER

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionManager : public GameObject
{
public:
	static void InitializeScorpion(const float timeToSpawnInSeconds);
	static void DeInitializeScorpion();

	ScorpionManager(const ScorpionManager &s) = delete;
	ScorpionManager& operator = (const ScorpionManager &) = delete;
	static void SetTimer();

	static void EndWave();

	static void Terminate(GameObject *);

private:
	ScorpionManager() = default;
	virtual ~ScorpionManager() = default;
	

	virtual void Alarm0() override;

	void SpawnScorpion() const;

	static ScorpionManager * GetInstance();

	static ScorpionManager* instance;

	float timeToSpawn;
	bool active;
};

#endif // !SPIDER_MANAGER
