#ifndef SCORPION_POOL
#define SCORPION_POOL

#include <list>

class Scorpion;
class GameObject;

class ScorpionPool
{
public:
	static Scorpion *GetScorpion();

	static void RecycleScorpion(GameObject * scorpion);

	ScorpionPool(const ScorpionPool &pool) = delete;
	ScorpionPool operator = (const ScorpionPool &pool) = delete;

	static void Terminate();
private:
	ScorpionPool() = default;
	~ScorpionPool() = default;


	static ScorpionPool * GetInstance();

	static ScorpionPool *instance;

	std::list<Scorpion*> recycledScorpions; ///this list will be used for purposes like healing broken mushrooms at new level

};

#endif // !SPIDER_POOL
