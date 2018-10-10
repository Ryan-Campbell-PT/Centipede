#include <random>

#include "FleaManager.h"
#include "TEAL/CommonElements.h"
#include "GameGrid.h"
#include "FleaFactory.h"
#include "MushroomFactory.h"
#include "Spider.h"

FleaManager *FleaManager::instance = 0;

FleaManager::FleaManager()
{
	MushroomFactory::AddNewObserver(this);
}

void FleaManager::InitializeFlea()
{
	GetInstance();
}

void FleaManager::ObserverUpdate(int numShrooms)
{
#if TESTING
	ConsoleMsg::WriteLine(Tools::ToString(numShrooms));
#endif
	if (numShrooms < SPAWN_FLEA_NUM)
		GetInstance()->SpawnFlea();
}

void FleaManager::SpawnFlea()
{	
	//randomly somewhere on x, always at the top y
	auto pos = sf::Vector2f(static_cast<float>(rand() % WindowManager::MainWindow.getSize().x), 0.f);
	GameGrid::GetCenterGridPosition(pos); //center on the grid

	FleaFactory::SpawnFlea(this, pos);
}

FleaManager * FleaManager::GetInstance()
{
	if (instance == 0)
		instance = new FleaManager;

	return instance;
}
