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

	GetInstance()->activeScorpions.push_back(scorpion);
	return scorpion;
}

void ScorpionPool::RecycleScorpion(GameObject * scorpion)
{
	GetInstance()->activeScorpions.remove(static_cast<Scorpion*>(scorpion));
	GetInstance()->recycledScorpions.push_front(static_cast<Scorpion*>(scorpion));
}

void ScorpionPool::Terminate()
{
	/**
	 * for whatever reason i cant delete these scorpions without a crash. 
	 * I assume it has to do with their managers being GO as well

	for (auto s : GetInstance()->recycledScorpions)
	{
		delete s;
		s = nullptr;
	}

	for (auto s : GetInstance()->activeScorpions)
	{
		delete s;
		s = nullptr;
	}
	*/

	delete instance;
	instance = nullptr;
}

ScorpionPool * ScorpionPool::GetInstance()
{
	if (instance == nullptr)
		instance = new ScorpionPool;

	return instance;
}
