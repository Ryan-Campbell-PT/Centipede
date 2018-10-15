#ifndef SPIDER_POOL
#define SPIDER_POOL

#include <list>

class Spider;

class SpiderPool
{
public:
	static Spider *GetSpider();
	static void RecycleSpider(Spider*const spider);

private:
	static SpiderPool * GetInstance();

	static SpiderPool *instance;

	std::list<Spider*> recycledSpiders; ///this list will be used for purposes like healing broken mushrooms at new level

};

#endif // !SPIDER_POOL
