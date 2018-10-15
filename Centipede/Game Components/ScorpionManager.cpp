#include "ScorpionManager.h"
#include "ScorpionFactory.h"
#include "GameGrid.h"

#include <random>

ScorpionManager *ScorpionManager::instance = nullptr;

void ScorpionManager::Alarm0()
{
	SpawnScorpion();
}

void ScorpionManager::Alarm1()
{
	SpawnScorpion();
}

void ScorpionManager::SpawnScorpion() const
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

void ScorpionManager::InitializeScorpion(const float timeToSpawnInSeconds)
{
	GetInstance()->SetAlarm(0, timeToSpawnInSeconds); //set a timer for when to spawn scorp
}

void ScorpionManager::RemoveScorpion(Scorpion * const scorpion)
{
	ScorpionFactory::RemoveScorpion(scorpion);

//todo: somehow fix this
}

ScorpionManager * ScorpionManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionManager;

	return instance;
}
