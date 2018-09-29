#include "MushroomFactory.h"
#include "Mushroom.h"
#include "GameGrid.h"
#include "Observee.h"

#include <random>

MushroomFactory * MushroomFactory::instance = 0; //necesary for linking

MushroomFactory::MushroomFactory()
{
}

void MushroomFactory::RemoveMushroom(Mushroom * shroom)
{
	GetInstance()->activeMushroomList.remove(shroom);
	GetInstance()->inactiveMushroomList.push_back(shroom);

	GetInstance()->UpdateObservees();
}

void MushroomFactory::AddNewObserver(Observer * o)
{
	GetInstance()->AddObservee(o);
}

void MushroomFactory::RemoveCurrentObserver(Observer * o)
{
	GetInstance()->RemoveObservee(o);
}

void MushroomFactory::UpdateObservees()
{
	for (auto o : this->obsereeList)
 		o->ObserverUpdate(this->activeMushroomList.size());
}

void MushroomFactory::SpawnMushroom(sf::Vector2f pos)
{
	Mushroom *m;

     	if (GetInstance()->inactiveMushroomList.size() == 0)
		m = new Mushroom(pos);

	else
	{
		//recycle from the list, taking from the back and using that
		m = GetInstance()->inactiveMushroomList.back();
		GetInstance()->inactiveMushroomList.pop_back();

		m->SetPosition(pos);
	}

		GetInstance()->activeMushroomList.push_back(m); //tell the game this mushroom is on the screen
}

void MushroomFactory::AddObservee(Observer * o)
{
	this->obsereeList.push_back(o);
}

void MushroomFactory::RemoveObservee(Observer * o)
{
	// ill deal with this later
}

MushroomFactory::~MushroomFactory()
{
}

MushroomFactory * MushroomFactory::GetInstance()
{
	if (MushroomFactory::instance == 0)
		MushroomFactory::instance = new MushroomFactory;

	return MushroomFactory::instance;
}

void MushroomFactory::InitializeMushroomField(int numShrooms)
{	
	float x, y;
	sf::Vector2f pos;

	int windowX = static_cast<int>(WindowManager::MainWindow.getView().getSize().x);
	int windowY = static_cast<int>(WindowManager::MainWindow.getView().getSize().y);
	int gridUnoccupied = static_cast<int>(GameGridEnum::Unoccupied);

	//for now, mushroom spawning is randomized by the given grid set in GameGrid
	for (int i = 0; i < numShrooms; ++i)
	{
		do
		{
			x = rand() % windowX;
			y = rand() % windowY;
		} while ((int)GameGrid::GetInstance()->GetGridStatus(sf::Vector2f(x, y)) >= gridUnoccupied);
		//the choice to use >= 0 is b/c when the array space is unused, its garbage data, typically -ABigNumber
		//so this tests whether its unusued, or Unoccupied

		pos.x = static_cast<float>(x); // + instead of a static_cast
		pos.y = static_cast<float>(y);

		GetInstance()->SpawnMushroom(pos);
	}
}
