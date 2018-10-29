#include "ScorpionManager.h"
#include "ScorpionFactory.h"
#include "GameGrid.h"

#include <random>

ScorpionManager *ScorpionManager::instance = nullptr;

void ScorpionManager::Alarm0()
{
	SpawnScorpion();
	ConsoleMsg::WriteLine("alarm 0 reached");
}

void ScorpionManager::SpawnScorpion() const
{
	const bool leftSide = rand() % 2; //either left or right side, determined by a random number
	int x;

	if (leftSide) //if its on the left side, then the x= 0
		x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		x = WindowManager::MainWindow.getSize().x;

	auto pos = sf::Vector2f(static_cast<float>(x), static_cast<float>(rand() % WindowManager::MainWindow.getSize().y));
	GameGrid::GetCenterYPosition(pos);

	ScorpionFactory::SpawnScorpion(pos);
	ConsoleMsg::WriteLine("scorp spawned");
	//GetInstance()->scorpion->SetSpawnSide(leftSide); //this is requried to spawn the scorp for whatever reason. todo: fix later
}

void ScorpionManager::InitializeScorpion(const float timeToSpawnInSeconds)
{
	GetInstance()->SetAlarm(0, timeToSpawnInSeconds); //set a timer for when to spawn scorp
	instance->timeToSpawn = timeToSpawnInSeconds;
	instance->active = true;
}

void ScorpionManager::DeInitializeScorpion()
{
	GetInstance()->active = false;
	instance->AlarmCancel(0);
}

void ScorpionManager::RemoveScorpion(Scorpion * const scorpion)
{
	ScorpionFactory::RemoveScorpion(scorpion);
	
	//whenever the scorp is removed, set an alarm for when it should spawn again
	if(instance)
	{
		GetInstance()->SetAlarm(0, instance->timeToSpawn);
		ConsoleMsg::WriteLine("scorp removed, setting alarm");
	}
}

void ScorpionManager::EndWave()
{
}

ScorpionManager * ScorpionManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionManager;

	return instance;
}
