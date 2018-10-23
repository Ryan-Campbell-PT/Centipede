#ifndef PLAYERDATA_H
#define PLAYERDATA_H

class PlayerInput;

struct PlayerData
{
	enum class PlayerID
	{
		Ai,
		Player1,
		Player2
	};

	PlayerData()
		: player(), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr)
	{
	}

	explicit PlayerData(PlayerID player)
		:player(player), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr) {}

	PlayerID player;
	int playerScore;
	int playerLives;
	int waveLevel;
	PlayerInput *playerInput;
};

#endif // PLAYERDATA_H
