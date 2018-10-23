#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>

//enum class PlayerID;

class PlayerInput;
struct PlayerData;

class PlayerManager
{
public:
	enum class PlayerID
	{
		Ai,
		Player1,
		Player2
	};

	static PlayerManager::PlayerID GetCurrentPlayer();
	static void InitializePlayer(PlayerID player);

	static void AddScore(const int score);
	static void LoseHealth();
	static void SetPlayerControls(PlayerInput *input);

private:
	PlayerManager();
	static PlayerManager* GetInstance();

	static PlayerManager* instance;
	PlayerData *currentPlayer;

	std::vector<PlayerData> listOfPlayers;
};

#endif // PLAYERMANAGER_H
