#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>
#include "PlayerData.h"

//enum class PlayerID;

class PlayerInput;
struct PlayerData;

class PlayerManager
{
public:

	static PlayerData::PlayerID GetCurrentPlayer();
	static void InitializePlayer(PlayerData::PlayerID player);

	static void AddScore(const int score);
	static void TakeDamage();
	static void SetPlayerControls(PlayerInput *input);

private:
	PlayerManager();
	void assignPlayerData(PlayerData::PlayerID player);
	static PlayerManager* GetInstance();

	static PlayerManager* instance;
	PlayerData currentPlayer;

	std::vector<PlayerData> listOfPlayers;
};

#endif // PLAYERMANAGER_H
