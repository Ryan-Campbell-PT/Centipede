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
#include "LivesManager.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::AddScore(const int score)
{
	GetInstance()->currentPlayer.playerScore += score;
	//	TextEditor::CurrentScore(instance->currentPlayer.playerScore);
}

void PlayerManager::PlayerDeath()
{
	GetInstance()->currentPlayer.playerLives--;

	//if we are set to 2 player mode, swap to next player
	if (instance->playerMode == PlayerMode::TwoPlayer)
	{
		instance->saveCurrentPlayerData();
		instance->SwapPlayer();
	}

	//if we no longer have any lives, end the game
	else if (instance->currentPlayer.playerLives <= 0)
		GameManager::EndGame();

	//if we are still alive, and are only a single player, restart the wave
	else
		GameManager::RestartWave();
}

void PlayerManager::SetPlayerControls(PlayerInput * input)
{
	//delete GetInstance()->currentPlayer.playerInput;

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
		GetInstance()->playerMode = PlayerMode::TwoPlayer; //todo: change this to two player mode
		InitializePlayer(PlayerData::PlayerID::Player2);
		break;

	default:
		break;
	}
}

void PlayerManager::SetMushroomField(std::list<Mushroom*>* list)
{
	GetInstance()->currentPlayer.mushroomSetup = list;
}

void PlayerManager::Terminate()
{
	delete instance;
	instance = nullptr;
}

PlayerManager::PlayerManager()
	:indexOfCurrentPlayer(-1)
{
	//emplace back essentially just takes the constructor of an object instead of calling the constructor
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Ai);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player1);
	this->listOfPlayers.emplace_back(PlayerData::PlayerID::Player2);
}

void PlayerManager::saveCurrentPlayerData()
{
	if (indexOfCurrentPlayer == -1)
	{//if we havent already modified the current player
		for (unsigned int i = 0; i < this->listOfPlayers.size(); ++i)
		{
			if (this->listOfPlayers[i].player == this->currentPlayer.player)
			{
				this->listOfPlayers[i] = this->currentPlayer;
				this->indexOfCurrentPlayer = i;
				break;
			}
		}
	}

	else
	{ //weve done this before
		this->listOfPlayers[this->indexOfCurrentPlayer] = this->currentPlayer;
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
		Ship::InitializeShip(new Ship_Ai);
		SoundManager::SetSoundProfile(new SoundOff);
		break;

	case PlayerData::PlayerID::Player1:
		Ship::InitializeShip(new Ship_Player);
		SoundManager::SetSoundProfile(new SoundOn);
		break;

	case PlayerData::PlayerID::Player2:
		Ship::InitializeShip(new Ship_Player); //todo: change this to two player mode
		SoundManager::SetSoundProfile(new SoundOn);
		break;

	default:
		break;
	}
}

void PlayerManager::SwapPlayer()
{//todo
#if false
	this->currentPlayer.mushroomSetup = MushroomManager::GetCurrentLayout();
	this->currentPlayer.playerScore = ScoreManager::GetCurrentScore();
	this->currentPlayer.waveLevel = WaveManager::GetCurrentWave();

	PlayerData tmp;
	if (this->currentPlayer.player == PlayerData::PlayerID::Player1)
		tmp.player = PlayerData::PlayerID::Player2;
	else if (this->currentPlayer.player == PlayerData::PlayerID::Player2)
		tmp.player = PlayerData::PlayerID::Player1;

	for (size_t i = 0; i < this->listOfPlayers.size() - 1; ++i)
	{
		//change the data of the list to the current players information
		if (this->listOfPlayers[i].player == this->currentPlayer.player)
			this->listOfPlayers[i] = this->currentPlayer;
		//look around for the player mode we are looking for
		if (tmp.player == this->listOfPlayers[i].player)
			tmp = this->listOfPlayers[i];
	}

	this->currentPlayer = tmp;

#elif true

	if(this->currentPlayer.player == PlayerData::PlayerID::Player1)
		this->currentPlayer = this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player2)];

	else if(this->currentPlayer.player == PlayerData::PlayerID::Player2)
		this->currentPlayer = this->listOfPlayers[static_cast<int>(PlayerData::PlayerID::Player1)];

	//we can assume now we swapped players and now have all the information necessary
	if(this->currentPlayer.playerLives <= 0)
		GameManager::EndGame(); //if we swapped players and this player has no lives, end the game

	else
	{ //now initialize all the data associated with this player
		WaveManager::SetupLevel(this->currentPlayer.waveLevel);
		ScoreManager::SetCurrentScore(this->currentPlayer.playerScore);
		MushroomManager::InitializeMushroomField(this->currentPlayer.mushroomSetup);
		LivesManager::DisplayLives(this->currentPlayer.playerLives);
	}

#endif
}

PlayerManager * PlayerManager::GetInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;

	return instance;
}
