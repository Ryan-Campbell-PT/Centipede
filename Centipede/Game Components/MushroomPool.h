#ifndef MUSHROOM_POOL
#define MUSHROOM_POOL

#include <list>

class Mushroom;

class MushroomPool
{
public:
	static Mushroom *GetMushroom();
	static void RecycleMushroom(Mushroom *shroom);
	
	static size_t GetNumActiveShrooms();
	static std::list<Mushroom*> GetActiveMushroomList();

	MushroomPool(const MushroomPool &pool) = delete;
	MushroomPool operator = (const MushroomPool &pool) = delete;

private:
	MushroomPool() = default;
	~MushroomPool();

	static MushroomPool * GetInstance();
	
	static MushroomPool *instance;

	std::list<Mushroom*> inactiveMushroomList; ///this list will be used for recycling purposes
	std::list<Mushroom*> activeMushroomList; ///this list will be used for purposes like healing broken mushrooms at new level

};

#endif // !MUSHROOM_POOL
