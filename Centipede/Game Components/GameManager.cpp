#include "GameManager.h"
#include "PlayerManager.h"
#include "HighScoreManager.h"

void GameManager::SetAttractorMode()
{
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	HighScoreManager::WriteHighScoreList();
	HighScoreManager::WriteHighScore();
}

void GameManager::SetPlayerMode()
{
}
