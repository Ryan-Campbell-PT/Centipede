#include <random>

#include "ScorpionFactory.h"
#include "Scorpion.h"

ScorpionFactory * ScorpionFactory::instance = 0;

ScorpionFactory::ScorpionFactory()
{
	this->scorpion = new Scorpion;
}

ScorpionFactory * ScorpionFactory::GetInstance()
{
	if (instance == 0)
		instance = new ScorpionFactory;

	return instance;
}

ScorpionFactory::~ScorpionFactory()
{
	delete this->scorpion;
}

void ScorpionFactory::SpawnScorpion(sf::Vector2f & pos)
{
	auto sPosition = sf::Vector2f(WindowManager::MainWindow.getSize().x, rand() % WindowManager::MainWindow.getSize().y);

}
