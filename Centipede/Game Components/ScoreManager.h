#ifndef SCORE_MANAGER
#define SCORE_MANAGER

#include <queue>

#include "TEAL/CommonElements.h"

class ScoreCmd;

class ScoreManager
{
private:
	//distance values
	static const int spiderDistNearMultiplier = 1 / 3;
	static const int spiderDistMedMultiplier = 2 / 3;
	static const int spiderDistFarMultiplier = 1;

	// Score values;
	static const int FleaDeath = 100;
	static const int ScorpionDeath = 200;
	static const int MushroomDeath = 300;
	static const int MushroomPoisonDeath = 400;
	static const int centiDeath = 300;

//#pragma warning (disable:E2404)
	static const int SpiderDeathFar = 500;
	static const int SpiderDistFar = WindowManager::MainWindow.getSize().x * spiderDistFarMultiplier;

	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = WindowManager::MainWindow.getSize().x * spiderDistMedMultiplier;

	static const int SpiderDeathNear = 700;
	static const int SpiderDistNear = WindowManager::MainWindow.getSize().x * spiderDistNearMultiplier;

	std::queue<ScoreCmd*> QueueCmds;

	static ScoreManager* ptrInstance;

	static ScoreManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager;
		return *ptrInstance;
	};

	void privProcessScore();

public:
	// events
	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled, CentiKilled };

	static void AddScore(int val);

	static ScoreCmd* GetScoreCommand(ScoreEvents ev);

	static void SendScoreCmd(ScoreCmd* c);
	static void ProcessScores();

};

#endif //SCORE_MANAGER
