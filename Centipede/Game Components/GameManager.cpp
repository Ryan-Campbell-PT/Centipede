#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"
#include "WaveManager.h"

void GameManager::SetAttractorMode()
{
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
	//todo: make sure that the wave is showing
	//coudl be done in this code
	WaveManager::WriteWaveText();
}

void GameManager::SetPlayerMode()
{
}
