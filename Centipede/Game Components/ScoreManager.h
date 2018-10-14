#ifndef SCORE_MANAGER
#define SCORE_MANAGER

#include <queue>

#include "TEAL/CommonElements.h"
#include "GameGrid.h"
#include "PlayerManager.h"

class ScoreCmd;
enum class PlayerID;

class ScoreManager
{
public:
	// events
	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled, CentiKilled };

	static void AddScore(int val);

	static ScoreCmd* GetScoreCommand(ScoreEvents ev);

	static void SendScoreCmd(ScoreCmd* c);
	static void ProcessScores();


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

	///due to the way const works, Im unable to get the MainWindow.GetSize().x like I would otherwise
	static const int SpiderDeathFar = 500;
	static const int SpiderDistFar = COLUMN * SPRITE_SIZE * spiderDistFarMultiplier;

	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = COLUMN * SPRITE_SIZE * spiderDistMedMultiplier;

	static const int SpiderDeathNear = 700;
	static const int SpiderDistNear = COLUMN * SPRITE_SIZE * spiderDistNearMultiplier;

	ScoreManager();

	static ScoreManager * GetInstance();

	void PrivProcessScore();

	std::queue<ScoreCmd*> QueueCmds;
	std::map<PlayerManager::PlayerID, int> scoreMap;
	
	static ScoreManager* instance;

};

#endif //SCORE_MANAGER
