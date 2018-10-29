#include <random>

#include "FleaManager.h"
#include "TEAL/CommonElements.h"
#include "GameGrid.h"
#include "FleaFactory.h"
#include "MushroomFactory.h"
#include "Spider.h"
#include "Flea.h"

FleaManager *FleaManager::instance = nullptr;

void FleaManager::EndWave()
{
}

FleaManager::FleaManager()
	:numShroomsToSpawn(0), fleaActive(false)
{
	MushroomFactory::AddNewObserver(this);
}

void FleaManager::InitializeFlea(const int numShroomsToSpawn)
{
	GetInstance()->numShroomsToSpawn = numShroomsToSpawn;
}

void FleaManager::DeInitializeFlea()
{
	MushroomFactory::RemoveCurrentObserver(GetInstance());
}

void FleaManager::SetNotActive()
{
	GetInstance()->fleaActive = false;
}

void FleaManager::ObserverUpdate(int numShrooms)
{
	if (numShrooms < numShroomsToSpawn)
		if(!fleaActive) //make sure only one is on the board
			GetInstance()->SpawnFlea();
}

void FleaManager::SpawnFlea()
{	
	//randomly somewhere on x, always at the top y
	auto pos = sf::Vector2f(static_cast<float>(rand() % WindowManager::MainWindow.getSize().x), 0.f);
	GameGrid::GetCenterGridPosition(pos); //center on the grid

	auto flea = FleaFactory::GetFlea();
	flea->RegisterToCurrentScene();
	flea->SpawnFlea(pos);
	fleaActive = true; ///make sure the game knows the flea is currently working
}

FleaManager * FleaManager::GetInstance()
{
	if (instance == nullptr)
		instance = new FleaManager;

	return instance;
}
