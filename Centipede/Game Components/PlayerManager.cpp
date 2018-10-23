#include "PlayerManager.h"
#include "Ship.h"
#include "ShipFSM.h"
#include "Ship_Ai.h"
#include "Ship_Player.h"
#include "PlayerData.h"
#include "PlayerInput.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::AddScore(const int score)
{
	/*for(auto player : GetInstance()->listOfPlayers)
		if(player.player == instance->currentPlayer)
			player.playerScore += score;*/
	GetInstance()->currentPlayer->playerScore += score;
}

void PlayerManager::LoseHealth()
{
	GetInstance()->currentPlayer->playerLives--;
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	delete instance->currentPlayer->playerInput;

	instance->currentPlayer->playerInput = input;
}

PlayerManager::PlayerManager()
	: currentPlayer()
{
	//emplace back essentially just takes the constructor of an object instead of calling the constructor
	this->listOfPlayers.emplace_back(PlayerID::Ai);
	this->listOfPlayers.emplace_back(PlayerID::Player1);
	this->listOfPlayers.emplace_back(PlayerID::Player2);
}

PlayerManager::PlayerID PlayerManager::GetCurrentPlayer()
{
	return GetInstance()->currentPlayer->player;
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

	for(auto playerr : GetInstance()->listOfPlayers)
		if(playerr.player == player)
			GetInstance()->currentPlayer = &playerr;
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
