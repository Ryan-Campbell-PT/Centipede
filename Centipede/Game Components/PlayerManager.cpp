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
	/*for(auto player : GetInstance()->listOfPlayers)
		if(player.player == instance->currentPlayer)
			player.playerScore += score;*/
	//todo: for some reason, the currnetPlayer deletes itself throughout the game life, find out why
	GetInstance()->currentPlayer->playerScore += score;
	TextEditor::CurrentScore(instance->currentPlayer->playerScore);
}

void PlayerManager::LoseHealth()
{
	GetInstance()->currentPlayer->playerLives--;
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	if (GetInstance()->currentPlayer)
	{
		delete instance->currentPlayer->playerInput;

		instance->currentPlayer->playerInput = input;
	}
}

PlayerManager::PlayerManager()
	:currentPlayer(nullptr)
{
	//emplace back essentially just takes the constructor of an object instead of calling the constructor
	this->listOfPlayers.emplace_back(PlayerID::Ai);
	this->listOfPlayers.emplace_back(PlayerID::Player1);
	this->listOfPlayers.emplace_back(PlayerID::Player2);

	//set the first player, cuz there is no simple way to just say "get player1"
	//for(auto player : this->listOfPlayers)
	//	if(player.player == PlayerID::Player1)
	//	{
	//		this->currentPlayer = &player;
	//		break;
	//	}
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

	for (auto playerr : GetInstance()->listOfPlayers)
		if (playerr.player == player)
		{
			GetInstance()->currentPlayer = &playerr;
			break;
		}
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
