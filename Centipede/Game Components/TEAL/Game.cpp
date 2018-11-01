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

using namespace std;

const sf::Keyboard::Key Game::KILLGAMEKEY = sf::Keyboard::Escape;
Game* Game::gameInstance = nullptr;

Game::Game()
{
	this->beat = SoundManager::GetSound(SoundManager::SoundEvent::Beat);
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
		//SoundManager::SendSoundCommand(gameInstance->beat);

		ScoreManager::ProcessScores();
		SoundManager::ProcessSounds();
	}

	Instance().TerminateGame();
}

void Game::TerminateGame()
{
	//ScorpionManager::Terminate();
	//SpiderManager::Terminate();

	// Clean up the managers
	SceneManager::Terminate();
	WindowManager::Terminate();
	ResourceManager::UnloadAllResources();
	

	// Clean up the game instance;
	delete gameInstance;
	//delete beat;
	gameInstance = nullptr;
	beat = nullptr;
}