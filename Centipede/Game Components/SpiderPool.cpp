#include "SpiderPool.h"
#include "Spider.h"

SpiderPool* SpiderPool::instance = nullptr;

Spider * SpiderPool::GetSpider()
{
	Spider * spider;
	if (GetInstance()->recycledSpiders.empty())
		spider = new Spider;

	else
	{
		spider = GetInstance()->recycledSpiders.front();
		GetInstance()->recycledSpiders.pop_front();
	}

	return spider;
}

void SpiderPool::RecycleSpider(Spider*const spider)
{
	GetInstance()->recycledSpiders.push_front(spider);
}


SpiderPool::~SpiderPool()
{
	for(auto s : this->recycledSpiders)
		delete s;

	delete instance;
}

SpiderPool * SpiderPool::GetInstance()
{
	if (instance == nullptr)
		instance = new SpiderPool;

	return instance;
}
