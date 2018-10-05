#ifndef SCORPION_POOL
#define SCORPION_POOL

#include <list>

class Scorpion;

class ScorpionPool
{
public:
	static Scorpion *GetScorpion();
	static void RecycleScorpion(Scorpion * const scorpion);

private:
	static ScorpionPool * GetInstance();

	static ScorpionPool *instance;

	std::list<Scorpion*> recycledScorpions; ///this list will be used for purposes like healing broken mushrooms at new level

};

#endif // !SPIDER_POOL
