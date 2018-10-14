#include "ScoreManager.h"
#include "ScoreValueCmd.h"
#include "ScoreByDistanceCmd.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager * ScoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ScoreManager;

	return instance;
};

void ScoreManager::PrivProcessScore()
{
	printf("\nProcessing all scores commands for this frame:\n");

	ScoreCmd* c = nullptr;

	if (!QueueCmds.empty())
	{ //this is simply so the WriteLine doesnt constantly print
		while (!QueueCmds.empty())
		{
			c = QueueCmds.front();
			c->Execute();

			QueueCmds.pop();
		}

		ConsoleMsg::WriteLine("Current Score: " + Tools::ToString(this->currentScore) + "\n");
	}
}

void ScoreManager::AddScore(int val)
{
	GetInstance()->currentScore += val;
}

ScoreCmd * ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	ScoreCmd* pCmd = nullptr;
	printf("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		printf("FleaDeath\n");
		pCmd = new ScoreValueCmd(FleaDeath);
		break;

	case ScoreEvents::ScorpionKilled:
		printf("ScorpionDeath\n");
		pCmd = new ScoreValueCmd(ScorpionDeath);
		break;

	case ScoreEvents::MushroomKilled:
		printf("MushroomDeath\n");
		pCmd = new ScoreValueCmd(MushroomDeath);
		break;

	case ScoreEvents::SpiderKilled:
		printf("SpiderDeath\n");
		pCmd = new ScoreByDistanceCmd(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;

	case ScoreEvents::MushroomPoisonKilled:
		printf("MushroomPoisonDeath\n");
		pCmd = new ScoreValueCmd(MushroomPoisonDeath);
		break;

	case ScoreEvents::CentiKilled:
		printf("CentiDeath\n");
		pCmd = new ScoreValueCmd(centiDeath);
		break;

	default:
		printf("<nothing>\n");
		break;
	}

	return pCmd;
}

void ScoreManager::SendScoreCmd(ScoreCmd * c)
{
	GetInstance()->QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	GetInstance()->PrivProcessScore();
}
