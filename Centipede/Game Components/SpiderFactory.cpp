#include "SpiderFactory.h"
#include "Spider.h"
#include "SpiderPool.h"


SpiderFactory *SpiderFactory::instance = nullptr;

SpiderFactory * SpiderFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new SpiderFactory;

	return instance;
}

Spider* SpiderFactory::GetSpider()
{
	return SpiderPool::GetSpider();
}

void SpiderFactory::RemoveSpider(Spider * const spider)
{
	SpiderPool::RecycleSpider(spider);
}
