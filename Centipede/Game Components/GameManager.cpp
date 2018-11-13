#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"
#include "WaveManager.h"
#include "ScoreManager.h"
#include "Ship.h"
#include "CentiHeadManager.h"
#include "Level1.h"
#include "LevelAttractor.h"
#include "MushroomManager.h"
#include "SpiderManager.h"
#include "ScorpionManager.h"
#include "UserInputManager.h"

void GameManager::SetAttractorMode()
{
	if (!SceneManager::GetCurrentScene())
		SceneManager::ChangeScene(new LevelAttractor);
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::Cleanup();
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
	ScoreManager::AttractorMode(true);
	//WaveManager::WriteWaveText();
	
}

void GameManager::SetPlayerMode(const PlayerData::PlayerID playerMode)
{
	//todo: when changing scenes, that arent the beginning, this breaks a lot
	SceneManager::ChangeScene(new Level1);
	PlayerManager::SetPlayerMode(playerMode);
	HighScoreManager::Cleanup();
	HighScoreManager::WriteHighScore();
	ScoreManager::AttractorMode(false);
}

void GameManager::RestartWave()
{//todo
	CentiHeadManager::RestartWave();
	//Ship::InitializeShip()
}

void GameManager::RequestUsername()
{
	Ship::RemoveInput(); //we dont want our typing to effect the ship
	CentiHeadManager::EndWave(); //remove all centipedes from screen
	SpiderManager::DeInitializeSpider();
	ScorpionManager::DeInitializeScorpion(); //make sure these two cant spawn anymore
	UserInputManager::RequestUsername();
}

void GameManager::EndGame()
{
	SceneManager::ChangeScene(new LevelAttractor);
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::Cleanup();
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
	HighScoreManager::EndGame();
	ScoreManager::AttractorMode(true);
}

void GameManager::EndGame_CheckHighScore()
{
	if(HighScoreManager::IsHighScore())
		RequestUsername();
	else
		EndGame();
}

void GameManager::EndWave()
{
	//depending on whether we are in attractor or player mode
	//it will determine what happens when all the centi are gone
	if (PlayerManager::GetCurrentPlayer() == PlayerData::PlayerID::Ai)
		CentiHeadManager::RestartWave();
	else
	{
		MushroomManager::EndWave();
		CentiHeadManager::EndWave();
		WaveManager::SetupLevel(WaveManager::GetCurrentWave() + 1);
	}
}
