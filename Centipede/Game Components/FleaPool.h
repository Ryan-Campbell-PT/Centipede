#ifndef FLEA_POOL_H
#define FLEA_POOL_H

#include <list>

class Flea;
class GameObject;

class FleaPool
{
public:
	///the manager will handle whether the flea can be spawned, and where it will be spawned
	///The pool only handles the recylcing
	static Flea *GetFlea();
	///if the flea needs to be removed, it will call this method
	///this method strictly handles the recycling of it, nothing more
	static void RecycleFlea(GameObject * flea);

	FleaPool(const FleaPool &pool) = delete;
	FleaPool operator = (const FleaPool &pool) = delete;

private:
	FleaPool();
	~FleaPool();

	static FleaPool * GetInstance();
	
	static FleaPool * instance;
	std::list<Flea*> fleaList;
};

#endif //FLEA_POOL_H