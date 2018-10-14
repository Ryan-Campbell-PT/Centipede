#include "PlayerManager.h"
#include "Ship.h"
#include "ShipFSM.h"
#include "Ship_Ai.h"
#include "Ship_Player.h"

PlayerManager * PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{

}

PlayerManager::PlayerID PlayerManager::GetCurrentPlayer()
{
	return GetInstance()->currentPlayer;
}

void PlayerManager::InitializePlayer(const PlayerID player)
{
	switch (player)
	{
	case PlayerID::Ai:
		Ship::SetState(&ShipFSM::aiMode);
		break;

	case PlayerID::Player1:
		Ship::SetState(&ShipFSM::playerMode);
		break;

	case PlayerID::Player2:
		Ship::SetState(&ShipFSM::playerMode);
		break;

	default:
		break;
	}

	GetInstance()->currentPlayer = player;
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
