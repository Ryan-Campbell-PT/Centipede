#include <random>

#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "MushroomFactory.h"

ScorpionFactory * ScorpionFactory::instance = 0;

ScorpionFactory::ScorpionFactory()
{
	this->scorpion = new Scorpion;
	MushroomFactory::GetInstance()->AddObservee(this);
}

ScorpionFactory * ScorpionFactory::GetInstance()
{
	if (instance == 0)
		instance = new ScorpionFactory;

	return instance;
}

void ScorpionFactory::ObserverUpdate(int numShrooms)
{
	if (numShrooms < SCORPIONSPAWN)
		SpawnScorpion();
}

ScorpionFactory::~ScorpionFactory()
{
	delete this->scorpion;
}

void ScorpionFactory::SpawnScorpion()
{
	auto sPosition = sf::Vector2f(WindowManager::MainWindow.getSize().x, rand() % WindowManager::MainWindow.getSize().y);
	this->scorpion->SpawnScorpion(sPosition);
}
