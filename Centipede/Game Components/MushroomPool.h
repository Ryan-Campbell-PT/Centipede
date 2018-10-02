#ifndef MUSHROOM_POOL
#define MUSHROOM_POOL

#include <list>

class Mushroom;

class MushroomPool
{
public:
	static MushroomPool * GetInstance();

	static Mushroom *GetMushroom();
	static void RecycleMushroom(Mushroom *shroom);

private:
	static MushroomPool *instance;

	std::list<Mushroom*> inactiveMushroomList; ///this list will be used for recycling purposes
	std::list<Mushroom*> activeMushroomList; ///this list will be used for purposes like healing broken mushrooms at new level

};

#endif // !MUSHROOM_POOL
