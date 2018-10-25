#include "ScorpionPool.h"
#include "Scorpion.h"

ScorpionPool *ScorpionPool::instance = 0;

Scorpion * ScorpionPool::GetScorpion()
{
	Scorpion * scorpion;
	if (GetInstance()->recycledScorpions.size() == 0)
		scorpion = new Scorpion;

	else
	{
		scorpion = GetInstance()->recycledScorpions.front();
		GetInstance()->recycledScorpions.pop_front();
	}

	return scorpion;
}

void ScorpionPool::RecycleScorpion(Scorpion  * const scorpion)
{
	GetInstance()->recycledScorpions.push_front(scorpion);
}

ScorpionPool::~ScorpionPool()
{
	for(auto s : this->recycledScorpions)
		delete s;

	delete instance;
}

ScorpionPool * ScorpionPool::GetInstance()
{
	if (instance == 0)
		instance = new ScorpionPool;

	return instance;
}
