#include "LevelAttractor.h"
#include "PlayerManager.h"
#include "MushroomManager.h"

LevelAttractor::LevelAttractor()
{
	MushroomManager::InitializeMushroomField(15);
}

void LevelAttractor::Initialize()
{
	//todo:
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	MushroomManager::InitializeMushroomField(15);

}

void LevelAttractor::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if(k == sf::Keyboard::Num1)
	{
		PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player1);
	}//one player mode

	else if(k == sf::Keyboard::Num2)
	{
		PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player2);
	}//two player mode
}
