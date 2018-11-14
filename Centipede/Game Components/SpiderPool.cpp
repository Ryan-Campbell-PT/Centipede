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

	GetInstance()->activeSpiders.push_back(spider);
	return spider;
}

void SpiderPool::RecycleSpider(GameObject *spider)
{
	GetInstance()->activeSpiders.remove(static_cast<Spider*>(spider));
	GetInstance()->recycledSpiders.push_front(static_cast<Spider*>(spider));
}

void SpiderPool::Terminate()
{
	/**
	 * for whatever reason i cant delete these spiders without a crash. 
	 * I assume it has to do with their managers being GO as well
	 
	for(auto f : GetInstance()->recycledSpiders)
	{
		delete f;
		f = nullptr;
	}

	for(auto f : GetInstance()->activeSpiders)
	{
		delete f;
		f = nullptr;
	}
	*/

	delete instance;
	instance = nullptr;
}

SpiderPool * SpiderPool::GetInstance()
{
	if (instance == nullptr)
		instance = new SpiderPool;

	return instance;
}
