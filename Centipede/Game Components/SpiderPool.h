#ifndef SPIDER_POOL
#define SPIDER_POOL

#include <list>

class Spider;
class GameObject;

class SpiderPool
{
public:
	static Spider *GetSpider();
	static void RecycleSpider(GameObject *spider);

	SpiderPool(const SpiderPool &pool) = delete;
	SpiderPool operator = (const SpiderPool &pool) = delete;

private:
	SpiderPool() = default;
	~SpiderPool();

	static SpiderPool * GetInstance();

	static SpiderPool *instance;

	std::list<Spider*> recycledSpiders;

};

#endif // !SPIDER_POOL
