#include "ScoreManager.h"
#include "ScoreValueCmd.h"
#include "ScoreByDistanceCmd.h"
#include "PlayerManager.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager()
{
	//add all the current ways a player can play (no way to programatically do this)
	GetInstance()->scoreMap.insert(std::pair<PlayerManager::PlayerID, int>(PlayerManager::PlayerID::Ai, 0));
	GetInstance()->scoreMap.insert(std::pair<PlayerManager::PlayerID, int>(PlayerManager::PlayerID::Player1, 0));
	GetInstance()->scoreMap.insert(std::pair<PlayerManager::PlayerID, int>(PlayerManager::PlayerID::Player2, 0));
}

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

		ConsoleMsg::WriteLine("Current Score: " + Tools::ToString(
			GetInstance()->scoreMap.at(PlayerManager::GetCurrentPlayer())) //print the current players score value
			+ "\n");
	}
}

void ScoreManager::AddScore(int val)
{
	//you have to get the players score first, then add to it the value added
	GetInstance()->scoreMap.at(PlayerManager::GetCurrentPlayer()) += val;
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
