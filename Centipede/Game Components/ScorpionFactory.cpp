#include <random>

#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "MushroomFactory.h"
#include "GameGrid.h"

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

void ScorpionFactory::SpawnScorpion()
{
	bool leftSide = rand() % 2; //either left or right side, determined by a random number
	float x;

	if (leftSide) //if its on the left side, then the x= 0
		x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		x = WindowManager::MainWindow.getSize().x; 

	auto pos = sf::Vector2f(x, rand() % WindowManager::MainWindow.getSize().y);
	GameGrid::GetInstance()->GetCenterGridPosition(pos);
	
	this->scorpion->SpawnScorpion(pos);
	this->scorpion->SetSpawnSide(leftSide); //this is requried to spawn the scorp for whatever reason. todo: fix later
}