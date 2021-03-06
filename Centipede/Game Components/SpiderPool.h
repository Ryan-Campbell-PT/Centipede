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

	static void Terminate();
private:
	SpiderPool() = default;
	~SpiderPool() = default;

	static SpiderPool * GetInstance();

	static SpiderPool *instance;

	std::list<Spider*> recycledSpiders;
	std::list<Spider*> activeSpiders;
};

#endif // !SPIDER_POOL
