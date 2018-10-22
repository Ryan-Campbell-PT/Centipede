#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include "ScoreManager.h"
#include "PlayerManager.h"

class PlayerInput;

struct PlayerData
{
	PlayerData()
		: player(), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr)
	{
	}

	explicit PlayerData(PlayerManager::PlayerID player)
		:player(player), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr) {}

	PlayerManager::PlayerID player;
	int playerScore;
	int playerLives;
	int waveLevel;
	PlayerInput *playerInput;
};

#endif // PLAYERDATA_H
