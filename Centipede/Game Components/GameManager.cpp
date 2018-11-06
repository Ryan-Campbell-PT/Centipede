#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"
#include "WaveManager.h"
#include "ScoreManager.h"
#include "LivesManager.h"
#include "Ship.h"
#include "CentiHeadManager.h"

void GameManager::SetAttractorMode()
{
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
	ScoreManager::AttractorMode(true);
	WaveManager::WriteWaveText();
}

void GameManager::SetPlayerMode()
{//todo
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player1);
	HighScoreManager::WriteHighScore();
	ScoreManager::AttractorMode(false);
	WaveManager::WriteWaveText();
	LivesManager::DisplayLives(LivesManager::GetStartingLives());
}

void GameManager::RestartWave()
{//todo
	CentiHeadManager::RestartWave();
}

void GameManager::EndGame()
{//todo
}
