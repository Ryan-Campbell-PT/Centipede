#ifndef SPIDER_MANAGER
#define SPIDER_MANAGER

#include "TEAL/CommonElements.h"

class Spider;

class SpiderManager : public GameObject
{
public:
	///we will assume that, per level, spiders only have one speed
	///and that will be shared in the manager and passed to each spider
	static void InitializeSpider(const float timeToSpawn, const float spiderSpeed = 1.5f);
	static void DeInitializeSpider();

	static void RemoveSpider(Spider * const spider);
	static void SetTimer();

	SpiderManager(const SpiderManager &s) = delete;
	SpiderManager& operator = (const SpiderManager &) = delete;
	static void EndWave();

	static void Terminate(GameObject *);
private:
	SpiderManager() = default;
	//virtual ~SpiderManager() = default;
	
	virtual void Alarm0() override;

	void SpawnSpider();

	static SpiderManager * GetInstance();

	static SpiderManager* instance;

	float spiderSpeed = 1.5f; //default speed
	float timeToSpawn;
	bool active;
};
#endif // !SPIDER_MANAGER
