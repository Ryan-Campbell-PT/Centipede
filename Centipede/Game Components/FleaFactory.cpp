#include "FleaFactory.h"
#include "MushroomFactory.h"
#include "Flea.h"
#include "GameGrid.h"
#include "Ship.h"

FleaFactory * FleaFactory::instance = 0;

FleaFactory::FleaFactory()
{
	MushroomFactory::AddNewObserver(this);
}

FleaFactory * FleaFactory::GetInstance()
{
	if (instance == 0)
		instance = new FleaFactory;

	return instance;
}

void FleaFactory::ObserverUpdate(int numShrooms)
{
#if TESTING
	ConsoleMsg::WriteLine(Tools::ToString(numShrooms));
#endif
	if (numShrooms < SPAWN_FLEA_NUM)
		SpawnFlea();
}

void FleaFactory::InitializeFlea()
{
	GetInstance()->flea = new Flea;
}

void FleaFactory::SpawnFlea()
{
	//this->state = new FleaState1;
	
	//find a random location on the screen to spawn the flea (x)
#if !TESTING
  	auto pos = sf::Vector2f(static_cast<float>(rand() % static_cast<int>(WindowManager::MainWindow.getView().getSize().x)), SPRITE_SIZE);
	GameGrid::GetCenterYPosition(pos); //set it in the middle of the grid
	GetInstance()->flea->SpawnFlea(pos);

#elif TESTING
	auto d = Ship::GetPosition();
	d.y = 0;
	GetInstance()->flea->SpawnFlea(d);

#endif
}
