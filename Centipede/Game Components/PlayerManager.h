#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

//enum class PlayerID;

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



private:
	PlayerManager();
	static PlayerManager* GetInstance();

	static PlayerManager* instance;
	PlayerID currentPlayer;
};

#endif // PLAYERMANAGER_H
