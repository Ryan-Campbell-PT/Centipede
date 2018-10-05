#ifndef FLEA_POOL_H
#define FLEA_POOL_H

#include <list>

#include "TEAL/CommonElements.h"

class Flea;

class FleaPool
{
public:
	///the manager will handle whether the flea can be spawned, and where it will be spawned
	///The pool only handles the recylcing
	static Flea *GetFlea();
	///if the flea needs to be removed, it will call this method
	///this method strictly handles the recycling of it, nothing more
	static void RecycleFlea(Flea *flea);

private:
	FleaPool();
	static FleaPool * GetInstance();
	
	static FleaPool * instance;
	std::list<Flea*> fleaList;
};

#endif //FLEA_POOL_H