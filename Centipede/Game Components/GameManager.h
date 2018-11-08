#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PlayerData.h"

class Scene;

///GameManager will handle game specific entities like ending the game,
///moving onto the next wave
class GameManager
{
public:
	static void SetAttractorMode();
	static void SetPlayerMode(PlayerData::PlayerID playerMode);
	static void RestartWave();
	static void EndGame();
	static void EndWave();

private:
	GameManager() = default;
};

#endif // GAMEMANAGER_H
