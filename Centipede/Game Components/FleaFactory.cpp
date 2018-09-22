#include "FleaFactory.h"
#include "MushroomFactory.h"
#include "Flea.h"
#include "GameGrid.h"

FleaFactory * FleaFactory::instance = 0;

FleaFactory::FleaFactory()
{
	MushroomFactory::GetInstance()->AddObservee(this);
	this->flea = new Flea;
}

FleaFactory * FleaFactory::GetInstance()
{
	if (instance == 0)
		instance = new FleaFactory;

	return instance;
}

void FleaFactory::ObserverUpdate(int numShrooms)
{
	if (numShrooms < SPAWN_FLEA_NUM)

		SpawnFlea();
}

void FleaFactory::SpawnFlea()
{
	//this->state = new FleaState1;
	
	//find a random location on the screen to spawn the flea (x)
  	auto pos = sf::Vector2f(rand() % (int)WindowManager::MainWindow.getView().getSize().x, SPRITE_SIZE);
	GameGrid::GetInstance()->GetCenterGridPosition(pos); //set it in the middle of the grid
}
