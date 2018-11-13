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
#include "../Explosion.h"
#include "../ExplosionManager.h"


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
	unsigned f = 0;
	while (WindowManager::MainWindow.isOpen() && ! sf::Keyboard::isKeyPressed( KILLGAMEKEY ) )
    {	
		// Adjust game time clock
		Instance().gameclock.ProcessTime();

		// Actual frame processing
		SceneManager::ProcessOneFrame();
		//SoundManager::SendSoundCommand(gameInstance->beat);

		ScoreManager::ProcessScores();
		SoundManager::ProcessSounds();
		//if(++f % 30 == 0)
			//ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::CritterDeath, sf::Vector2f(300,300));
	}

	Instance().TerminateGame();
}

void Game::TerminateGame()
{
	// Clean up the managers
	SceneManager::Terminate();
	WindowManager::Terminate();
	ResourceManager::UnloadAllResources();

	MushroomManager::Terminate();
	FleaManager::Terminate();
	CentiHeadManager::Terminate();
	CentiBodyManager::Terminate();
	BulletManager::Terminate();

	GameGrid::Terminate();
	PlayerManager::Terminate();
	WaveManager::Terminate();

	// Clean up the game instance;
	//todo: be sure to check beat
	delete gameInstance;
	//delete beat;
	gameInstance = nullptr;
	//beat = nullptr;

	//_CrtDumpMemoryLeaks();  

}