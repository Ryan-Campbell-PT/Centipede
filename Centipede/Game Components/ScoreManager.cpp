#include "ScoreManager.h"
#include "ScoreValueCmd.h"

void ScoreManager::privProcessScore()
{
}

void ScoreManager::AddScore(int val)
{
}

ScoreCmd * ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	ScoreCmd* pCmd = nullptr;
	printf("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		printf("FleaDeath\n");
		pCmd = new ScoreValueCmd( FleaDeath );
		break;
	case ScoreEvents::ScorpionKilled:
		printf("ScorpionDeath\n");
		pCmd = new ScoreValueCmd( ScorpionDeath );
		break;
	case ScoreEvents::MushroomKilled:
		printf("MushroomDeath\n");
		pCmd = new ScoreValueCmd( MushroomDeath );
		break;
	case ScoreEvents::SpiderKilled:
		printf("SpiderDeath\n");
		pCmd = new CmdScoreByDistance(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			                          SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;
	case ScoreEvents::MushroomPoisonKilled:
		printf("MushroomPoisonDeath\n");
		pCmd = new ScoreValueCmd( MushroomPoisonDeath );
		break;
	default:
		printf("<nothing>\n");
		break;
	}

	return pCmd;
}

void ScoreManager::SendScoreCmd(CmdScore * c)
{
}

void ScoreManager::ProcessScores()
{
	Instance().privProcessScore();
}
