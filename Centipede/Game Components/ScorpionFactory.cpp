#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "ScorpionPool.h"

ScorpionFactory * ScorpionFactory::instance = nullptr;

ScorpionFactory * ScorpionFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionFactory;

	return instance;
}

ScorpionFactory::~ScorpionFactory()
{
	delete instance;
}

Scorpion * ScorpionFactory::GetScorpion()
{
	return ScorpionPool::GetScorpion();
}