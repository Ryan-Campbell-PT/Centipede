#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <list>

class PlayerInput;
class Mushroom;

struct PlayerData
{
	enum class PlayerID
	{
		Ai,
		Player1,
		Player2
	};

	PlayerData()
		: player(), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr), mushroomSetup(nullptr)
	{
	}

	explicit PlayerData(PlayerID player)
		:player(player), playerScore(0), playerLives(3), waveLevel(1), playerInput(nullptr), mushroomSetup(nullptr) {}

	PlayerID player;
	int playerScore;
	int playerLives;
	int waveLevel;
	PlayerInput *playerInput;
	std::list<Mushroom*> *mushroomSetup; //a pointer to the current used mushroom field setup
};

#endif // PLAYERDATA_H
