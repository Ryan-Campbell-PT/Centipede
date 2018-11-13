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
#include "SoundOff.h"
#include "SoundOn.h"
#include "GameManager.h"
#include "LivesWriter.h"
#include "CentiHeadManager.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::AddScore(const int score)
{
	GetInstance()->currentPlayer.playerScore += score;
}

void PlayerManager::PlayerDeath()
{
	GetInstance()->currentPlayer.playerLives--;

	//if we are set to 2 player mode, swap to next player
	if (instance->playerMode == PlayerMode::TwoPlayer)
	{
		CentiHeadManager::EndWave();
		instance->saveCurrentPlayerData();
		instance->SwapPlayer();
	}

	//if we no longer have any lives, end the game
	else if (instance->currentPlayer.playerLives <= 0)
		GameManager::EndGame_CheckHighScore();

	//if we are still alive, and are only a single player, restart the wave
	else
	{
		GameManager::RestartWave();
		LivesWriter::WriteLives(instance->currentPlayer.playerLives);
	}
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	instance->currentPlayer.playerInput = input;
}

void PlayerManager::SetPlayerMode(PlayerData::PlayerID player)
{
	switch (player)
	{
	case PlayerData::PlayerID::Ai:
		GetInstance()->playerMode = PlayerMode::Attractor;
		InitializePlayer(PlayerData::PlayerID::Ai);
		break;

	case PlayerData::PlayerID::Player1:
		GetInstance()->playerMode = PlayerMode::OnePlayer;
		InitializePlayer(PlayerData::PlayerID::Player1);
		break;

	case PlayerData::PlayerID::Player2:
		GetInstance()->playerMode = PlayerMode::TwoPlayer;
		InitializePlayer(PlayerData::PlayerID::Player1); //start out on player 1 anyways, but will swap after death
		break;

	default:
		break;
	}
}

void PlayerManager::SetMushroomField(std::list<Mushroom*>* list)
{
	GetInstance()->currentPlayer.mushroomSetup = list;
}

void PlayerManager::ReinitializeShip()
{
	InitializePlayer(instance->currentPlayer.player);
}

void PlayerManager::Terminate()
{
	delete instance;
	instance = nullptr;
}

PlayerManager::PlayerManager()
	:indexOfCurrentPlayer(0)
{
	//emplace back essentially just takes the constructor of an object instead of calling the constructor
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Ai);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player1);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player2);
}

void PlayerManager::saveCurrentPlayerData()
{
	if (this->currentPlayer.player == PlayerData::PlayerID::Player1)
	{
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player1)] = this->currentPlayer;
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player1)].mushroomSetup = MushroomManager::GetCurrentLayout();
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player1)].waveLevel = WaveManager::GetCurrentWave();
	}

	else if (this->currentPlayer.player == PlayerData::PlayerID::Player2)
	{
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player2)] = this->currentPlayer;
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player2)].mushroomSetup = MushroomManager::GetCurrentLayout();
		this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player2)].waveLevel = WaveManager::GetCurrentWave();
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
		Ship::InitializeShip(Ship::ShipModeEnum::Attractor);
		SoundManager::SetSoundProfile(new SoundOff);
		break;

	case PlayerData::PlayerID::Player1:
		Ship::InitializeShip(Ship::ShipModeEnum::Player);
		instance->currentPlayer.player = PlayerData::PlayerID::Player1;
		SoundManager::SetSoundProfile(new SoundOn);
		break;

	case PlayerData::PlayerID::Player2:
		Ship::InitializeShip(Ship::ShipModeEnum::Player);
		instance->currentPlayer.player = PlayerData::PlayerID::Player1;
		SoundManager::SetSoundProfile(new SoundOn);
		break;

	default:
		break;
	}

	if (GetInstance()->playerMode != PlayerMode::Attractor)
		LivesWriter::WriteLives(instance->currentPlayer.playerLives);
}

void PlayerManager::SwapPlayer()
{
	if (this->currentPlayer.player == PlayerData::PlayerID::Player1)
		this->currentPlayer = this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player2)];

	else if (this->currentPlayer.player == PlayerData::PlayerID::Player2)
		this->currentPlayer = this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player1)];

	//we can assume now we swapped players and now have all the information necessary
	if (this->currentPlayer.playerLives <= 0)
		GameManager::EndGame_CheckHighScore(); //if we swapped players and this player has no lives, end the game

	else
	{ //now initialize all the data associated with this player
		WaveManager::SetupLevel(this->currentPlayer.waveLevel);
		ScoreManager::SetCurrentScore(this->currentPlayer.playerScore);
		MushroomManager::InitializeMushroomField(this->currentPlayer.mushroomSetup);
		LivesWriter::WriteLives(instance->currentPlayer.playerLives);
	}
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
