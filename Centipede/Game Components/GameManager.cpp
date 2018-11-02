#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"
#include "WaveManager.h"
#include "ScoreManager.h"

void GameManager::SetAttractorMode()
{
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
	ScoreManager::AttractorMode(true);
	WaveManager::WriteWaveText();
}

void GameManager::SetPlayerMode()
{
}
