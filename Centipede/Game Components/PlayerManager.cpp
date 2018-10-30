#include "PlayerManager.h"
#include "Ship.h"
#include "ShipFSM.h"
#include "Ship_Ai.h"
#include "Ship_Player.h"
#include "PlayerData.h"
#include "PlayerInput.h"
#include "TextEditor.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "WaveManager.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::AddScore(const int score)
{
	GetInstance()->currentPlayer.playerScore += score;
	TextEditor::CurrentScore(instance->currentPlayer.playerScore);
}

void PlayerManager::PlayerDeath()
{
	if(GetInstance()->playerMode == PlayerMode::TwoPlayer)
		instance->SwapPlayer();

	if (--instance->currentPlayer.playerLives <= 0)
	{
		//todo: save info for current player

	}
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	delete GetInstance()->currentPlayer.playerInput;

	instance->currentPlayer.playerInput = input;
}

void PlayerManager::SetPlayerMode(PlayerData::PlayerID player)
{
	switch (player)
	{
	case PlayerData::PlayerID::Ai:
		GetInstance()->playerMode = PlayerMode::Attractor;
		instance->InitializePlayer(PlayerData::PlayerID::Ai);
		break;

	case PlayerData::PlayerID::Player1:
		GetInstance()->playerMode = PlayerMode::OnePlayer;
		instance->InitializePlayer(PlayerData::PlayerID::Player1);
		break;

	case PlayerData::PlayerID::Player2:
		GetInstance()->playerMode = PlayerMode::TwoPlayer; //todo: change this to two player mode
		instance->InitializePlayer(PlayerData::PlayerID::Player2);
		break;

	default:
		break;
	}
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
		Ship::SetState(&ShipFSM::playerMode); //todo: change this to two player mode
		break;

	default:
		break;
	}

	GetInstance()->assignPlayerData(player);

}

void PlayerManager::SwapPlayer()
{
	this->currentPlayer.mushroomSetup = MushroomManager::GetCurrentLayout();
	this->currentPlayer.playerScore = ScoreManager::GetCurrentScore();
	this->currentPlayer.waveLevel = WaveManager::GetCurrentWave();

	for (size_t i = 0; i < this->listOfPlayers.size() - 1; ++i)
		if (this->listOfPlayers[i].player == this->currentPlayer.player)
			this->listOfPlayers[i] = this->currentPlayer;
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
