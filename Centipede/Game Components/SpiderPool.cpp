#include "SpiderPool.h"
#include "Spider.h"

SpiderPool* SpiderPool::instance = 0;

Spider * SpiderPool::GetSpider()
{
	Spider * spider;
	if (GetInstance()->recycledSpiders.size() == 0)
		spider = new Spider;

	else
	{
		spider = GetInstance()->recycledSpiders.front();
		GetInstance()->recycledSpiders.pop_front();
	}

	return spider;
}

void SpiderPool::RecycleSpider(Spider * spider)
{
	GetInstance()->recycledSpiders.push_front(spider);
}


SpiderPool * SpiderPool::GetInstance()
{
	if (instance == 0)
		instance = new SpiderPool;

	return instance;
}
