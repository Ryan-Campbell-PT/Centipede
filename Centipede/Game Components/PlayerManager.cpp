#include "PlayerManager.h"
#include "Ship.h"
#include "ShipFSM.h"
#include "Ship_Ai.h"
#include "Ship_Player.h"
#include "PlayerData.h"
#include "PlayerInput.h"
#include "TextEditor.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::AddScore(const int score)
{
	GetInstance()->currentPlayer.playerScore += score;
	TextEditor::CurrentScore(instance->currentPlayer.playerScore);
}

void PlayerManager::TakeDamage()
{
	GetInstance()->currentPlayer.playerLives--;
	//todo:after this, we want to initialize the next player
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	delete GetInstance()->currentPlayer.playerInput;

	instance->currentPlayer.playerInput = input;
}

PlayerManager::PlayerManager()
{
	//emplace back essentially just takes the constructor of an object instead of calling the constructor
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Ai);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player1);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player2);
}

void PlayerManager::assignPlayerData(PlayerData::PlayerID player)
{
	//this loop handles modifying the list, so we can get the information back later again
	int counter = 0;
	for (const auto playerr : this->listOfPlayers)
	{
		if (playerr.player == this->currentPlayer.player)
		{
			this->listOfPlayers[counter] = this->currentPlayer;
			break;
		}
		++counter;
	}

	//this loop handles setting the current player to the player specified
	for (const auto playerr : this->listOfPlayers)
		if (playerr.player == player)
		{
			this->currentPlayer = playerr;
			break;
		}
}

PlayerData::PlayerID PlayerManager::GetCurrentPlayer()
{
	return GetInstance()->currentPlayer.player;
}

void PlayerManager::InitializePlayer(PlayerData::PlayerID player)
{
	switch (player)
	{
	case PlayerData::PlayerID::Ai:
		Ship::SetState(&ShipFSM::aiMode);
		break;

	case PlayerData::PlayerID::Player1:
		Ship::SetState(&ShipFSM::playerMode);
		break;

	case PlayerData::PlayerID::Player2:
		Ship::SetState(&ShipFSM::playerMode);
		break;

	default:
		break;
	}

	GetInstance()->assignPlayerData(player);

}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
