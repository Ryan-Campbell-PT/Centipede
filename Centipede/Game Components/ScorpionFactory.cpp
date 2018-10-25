#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "ScorpionPool.h"

ScorpionFactory * ScorpionFactory::instance = 0;

ScorpionFactory * ScorpionFactory::GetInstance()
{
	if (instance == 0)
		instance = new ScorpionFactory;

	return instance;
}

ScorpionFactory::ScorpionFactory()
{
}

ScorpionFactory::~ScorpionFactory()
{
	delete instance;
}

void ScorpionFactory::SpawnScorpion(sf::Vector2f pos)
{	
	auto scorpion = ScorpionPool::GetScorpion();
	scorpion->SpawnScorpion(pos);
	//scorpion->SetSpawnSide(leftSide); //this is requried to spawn the scorp for whatever reason. todo: fix later
}

void ScorpionFactory::RemoveScorpion(Scorpion * const scorpion)
{
	ScorpionPool::RecycleScorpion(scorpion);
}
