#ifndef SPIDER_MANAGER
#define SPIDER_MANAGER

#include "TEAL/CommonElements.h"

class Spider;

class SpiderManager
{
public:
	static void SpawnSpider();

	static void RemoveSpider(Spider * const shroom);

private:
	static SpiderManager * GetInstance();

	static SpiderManager* instance;
};
#endif // !SPIDER_MANAGER
