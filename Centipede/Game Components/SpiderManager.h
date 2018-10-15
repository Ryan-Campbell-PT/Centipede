#ifndef SPIDER_MANAGER
#define SPIDER_MANAGER

#include "TEAL/CommonElements.h"

#define DEFAULT_SPIDER_SPEED 1.5f

class Spider;

class SpiderManager : public GameObject
{
public:
	///we will assume that, per level, spiders only have one speed
	///and that will be shared in the manager and passed to each spider
	static void InitializeSpider(const int timeToSpawn, const float spiderSpeed = DEFAULT_SPIDER_SPEED);


	static void RemoveSpider(Spider * const spider);

private:
	virtual void Alarm0() override;
	virtual void Alarm1() override;

	void SpawnSpider();

	static SpiderManager * GetInstance();

	static SpiderManager* instance;

	float spiderSpeed;
};
#endif // !SPIDER_MANAGER
