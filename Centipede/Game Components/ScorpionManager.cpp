#include "ScorpionManager.h"
#include "ScorpionFactory.h"
#include "GameGrid.h"

#include <random>

ScorpionManager *ScorpionManager::instance = 0;

void ScorpionManager::SpawnScorpion()
{
	bool leftSide = rand() % 2; //either left or right side, determined by a random number
	int x;

	if (leftSide) //if its on the left side, then the x= 0
		x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		x = WindowManager::MainWindow.getSize().x;

	auto pos = sf::Vector2f(static_cast<float>(x), static_cast<float>(rand() % WindowManager::MainWindow.getSize().y));
	GameGrid::GetCenterYPosition(pos);

	ScorpionFactory::SpawnScorpion(pos);
	//GetInstance()->scorpion->SetSpawnSide(leftSide); //this is requried to spawn the scorp for whatever reason. todo: fix later
}

void ScorpionManager::RemoveScorpion(Scorpion * const scorpion)
{
	ScorpionFactory::RemoveScorpion(scorpion);
}

ScorpionManager * ScorpionManager::GetInstance()
{
	if (instance == 0)
		instance = new ScorpionManager;

	return instance;
}
