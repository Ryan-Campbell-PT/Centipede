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
	static void SetMushroomField(std::list<Mushroom*>* list);

	static void Terminate();

private:
	enum class PlayerMode
	{
		Attractor = 0, OnePlayer = 1, TwoPlayer	 = 2
	};

	PlayerManager();
	void saveCurrentPlayerData();
	//void initializeNewPlayer
	static PlayerManager* GetInstance();

	///when swapping players, the info will be stored for further use
	void SwapPlayer(); 

	static PlayerManager* instance;
	PlayerData currentPlayer;
	PlayerMode playerMode;
	std::vector<PlayerData> listOfPlayers;
	int indexOfCurrentPlayer;
};

#endif // PLAYERMANAGER_H
