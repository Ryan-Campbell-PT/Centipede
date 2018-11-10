#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"
#include "WaveManager.h"
#include "ScoreManager.h"
#include "Ship.h"
#include "CentiHeadManager.h"
#include "Level1.h"
#include "LevelAttractor.h"

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

void GameManager::EndWave()
{
	//depending on whether we are in attractor or player mode
	//it will determine what happens when all the centi are gone
	if (PlayerManager::GetCurrentPlayer() == PlayerData::PlayerID::Ai)
		CentiHeadManager::RestartWave();
	else
		WaveManager::SetupLevel(WaveManager::GetCurrentWave() + 1);
}
