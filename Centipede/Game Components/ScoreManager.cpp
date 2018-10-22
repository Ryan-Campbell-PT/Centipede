#include "ScoreManager.h"
#include "ScoreValueCmd.h"
#include "ScoreByDistanceCmd.h"
#include "PlayerManager.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager()
{
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

		std::string player;
		if(PlayerManager::GetCurrentPlayer() == PlayerManager::PlayerID::Player1)
			player = "Player1";
		else
			player = "Player2";

		//ConsoleMsg::WriteLine(player + "'s current Score: " + Tools::ToString(
		//	GetInstance()->scoreMap.at(PlayerManager::GetCurrentPlayer())) //print the current players score value
		//	+ "\n");
	}
}

void ScoreManager::AddScore(int val)
{
	//you have to get the players score first, then add to it the value added
	//GetInstance()->scoreMap.at(PlayerManager::GetCurrentPlayer()) += val;
	//todo: may want to keep a local score value, and then send over the data to the player after they lose.
	PlayerManager::AddScore(val);
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
