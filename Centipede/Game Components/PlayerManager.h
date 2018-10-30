#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>
#include "PlayerData.h"

//enum class PlayerID;

class PlayerInput;
struct PlayerData;
class ShipMode;

class PlayerManager
{
public:

	static PlayerData::PlayerID GetCurrentPlayer();
	static void InitializePlayer(PlayerData::PlayerID player);

	static void AddScore(const int score);
	static void PlayerDeath();
	static void SetPlayerControls(PlayerInput *input);
	static void SetPlayerMode(PlayerData::PlayerID player);

private:
	enum class PlayerMode
	{
		Attractor, OnePlayer, TwoPlayer	
	};

	PlayerManager();
	void assignPlayerData(PlayerData::PlayerID player);
	static PlayerManager* GetInstance();

	///when swapping players, the info will be stored for further use
	void SwapPlayer(); 

	static PlayerManager* instance;
	PlayerData currentPlayer;
	PlayerMode playerMode;
	std::vector<PlayerData> listOfPlayers;
};

#endif // PLAYERMANAGER_H
