#include "ScorpionPool.h"
#include "Scorpion.h"

ScorpionPool *ScorpionPool::instance = nullptr;

Scorpion * ScorpionPool::GetScorpion()
{
	Scorpion * scorpion;
	if (GetInstance()->recycledScorpions.empty())
	{
		scorpion = new Scorpion;
		///returns to RecycleScorpion when the object is destroyed
		scorpion->SetExternalManagement(RecycleScorpion);
	}

	else
	{
		scorpion = GetInstance()->recycledScorpions.front();
		GetInstance()->recycledScorpions.pop_front();
		scorpion->RegisterToCurrentScene();
	}

	return scorpion;
}

void ScorpionPool::RecycleScorpion(GameObject * scorpion)
{
	GetInstance()->recycledScorpions.push_front(static_cast<Scorpion*>(scorpion));
}

ScorpionPool::~ScorpionPool()
{
	for(auto s : this->recycledScorpions)
		delete s;

	delete instance;
}

ScorpionPool * ScorpionPool::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionPool;

	return instance;
}
