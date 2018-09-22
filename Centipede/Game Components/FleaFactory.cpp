#include "FleaFactory.h"
#include "MushroomFactory.h"
#include "Flea.h"
#include "GameGrid.h"
#include "Ship.h"

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
#if false
  	auto pos = sf::Vector2f(rand() % (int)WindowManager::MainWindow.getView().getSize().x, SPRITE_SIZE);
	GameGrid::GetInstance()->GetCenterGridPosition(pos); //set it in the middle of the grid
	this->flea->SpawnFlea(pos);

#elif true
	auto d = Ship::GetInstance()->Pos;
	d.y = 0;
	flea->SpawnFlea(d);

#endif
}
