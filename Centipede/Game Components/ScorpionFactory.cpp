#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "ScorpionPool.h"

ScorpionFactory * ScorpionFactory::instance = nullptr;

void ScorpionFactory::Terminate()
{
	delete instance;
	instance = nullptr;
	
	ScorpionPool::Terminate();
}

ScorpionFactory * ScorpionFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionFactory;

	return instance;
}

Scorpion * ScorpionFactory::GetScorpion()
{
	return ScorpionPool::GetScorpion();
}