// Game.h
// Andre Berthiaume, Juen 2012
//
// Main game loop

#include "Game.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "SceneManager.h"
#include "Tools.h"
#include "../ScoreManager.h"
#include "../SoundCmd.h"
#include "../ScorpionManager.h"
#include "../SpiderManager.h"
#include "../ScorpionPool.h"
#include "../MushroomManager.h"
#include "../FleaManager.h"
#include "../CentiHeadManager.h"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include "../GameManager.h"
#include "../WaveManager.h"
#include "../Ship.h"
#include "../BulletManager.h"
#include "../CentiHeadPool.h"
#include "../ExplosionManager.h"
#include "../TextEditor.h"


using namespace std;

const sf::Keyboard::Key Game::KILLGAMEKEY = sf::Keyboard::Escape;
Game* Game::gameInstance = nullptr;

Game::Game()
{
}

void Game::Run()
{
	// Seed the random generator (Haven't found a more logical spot for it yet...)
	srand(static_cast<unsigned>(time(nullptr)));

	// Set up the window 
	WindowManager::Initialize();

	// Load resources
	ResourceManager::LoadAllResources();

	while (WindowManager::MainWindow.isOpen() && ! sf::Keyboard::isKeyPressed( KILLGAMEKEY ) )
    {	
		// Adjust game time clock
		Instance().gameclock.ProcessTime();

		// Actual frame processing
		SceneManager::ProcessOneFrame();

		ScoreManager::ProcessScores();
		SoundManager::ProcessSounds();
	}

	Instance().TerminateGame();
}

void Game::TerminateGame()
{
	// Clean up the managers
	SceneManager::Terminate();
	WindowManager::Terminate();
	ResourceManager::UnloadAllResources();

	GameGrid::Terminate();
	PlayerManager::Terminate();
	WaveManager::Terminate();
	TextEditor::Terminate();
	SoundManager::Terminate();

	// Clean up the game instance;
	delete gameInstance;
	gameInstance = nullptr;
}