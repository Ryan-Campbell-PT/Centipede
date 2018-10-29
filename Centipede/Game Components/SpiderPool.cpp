#include "SpiderPool.h"
#include "Spider.h"

SpiderPool* SpiderPool::instance = nullptr;

Spider * SpiderPool::GetSpider()
{
	Spider * spider;
	if (GetInstance()->recycledSpiders.empty())
	{
		spider = new Spider;
		spider->SetExternalManagement(RecycleSpider);
	}

	else
	{
		spider = GetInstance()->recycledSpiders.front();
		GetInstance()->recycledSpiders.pop_front();
	}

	return spider;
}

void SpiderPool::RecycleSpider(GameObject *spider)
{
	GetInstance()->recycledSpiders.push_front(static_cast<Spider*>(spider));
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
