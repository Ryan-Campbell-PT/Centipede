#include "SpiderFactory.h"
#include "Spider.h"
#include "SpiderPool.h"


SpiderFactory *SpiderFactory::instance = 0;

SpiderFactory::SpiderFactory()
{
	this->spider = new Spider;
}


SpiderFactory * SpiderFactory::GetInstance()
{
	if (instance == 0)
		instance = new SpiderFactory;

	return instance;
}

void SpiderFactory::SpawnSpider(sf::Vector2f &pos)
{
	auto spider = SpiderPool::GetSpider();
	spider->SpawnSpider(pos);
}

void SpiderFactory::RemoveSpider(Spider * const spider)
{
	SpiderPool::RecycleSpider(spider);
}
