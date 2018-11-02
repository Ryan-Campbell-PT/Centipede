#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

///GameManager will handle game specific entities like ending the game,
///moving onto the next wave
class GameManager
{
public:
	static void SetAttractorMode();
	static void SetPlayerMode();

private:
	GameManager() = default;
};

#endif // GAMEMANAGER_H
