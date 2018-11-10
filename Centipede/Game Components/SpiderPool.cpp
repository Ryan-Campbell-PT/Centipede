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
		spider->RegisterToCurrentScene();
	}

	return spider;
}

void SpiderPool::RecycleSpider(GameObject *spider)
{
	GetInstance()->recycledSpiders.push_front(static_cast<Spider*>(spider));
}


void SpiderPool::Terminate()
{
	//for(auto f : GetInstance()->recycledSpiders)
	//	delete f;

	delete instance;
	instance = nullptr;
}

SpiderPool * SpiderPool::GetInstance()
{
	if (instance == nullptr)
		instance = new SpiderPool;

	return instance;
}
