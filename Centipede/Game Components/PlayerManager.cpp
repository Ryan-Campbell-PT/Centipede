#include "PlayerManager.h"
#include "Ship.h"

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
		Ship::SetState(ShipFSM::Ai);
		break;

	case PlayerID::Player1:
		Ship::SetState(ShipFSM::Player);
		break;

	case PlayerID::Player2:
		Ship::SetState(ShipFSM::Player);
		break;

	default:
		break;
	}

	this->currentPlayer = player;
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
