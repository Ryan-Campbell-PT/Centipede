#include "SpiderManager.h"
#include "Spider.h"
#include "SpiderFactory.h"
#include <random>

SpiderManager* SpiderManager::instance = nullptr;

SpiderManager * SpiderManager::GetInstance()
{
	if (instance == nullptr)
		instance = new SpiderManager;

	return instance;
}

void SpiderManager::InitializeSpider(const float timeToSpawn, const float spiderSpeed)
{
	GetInstance()->spiderSpeed = spiderSpeed;

	GetInstance()->timeToSpawn = timeToSpawn;
	instance->SetAlarm(0, timeToSpawn);
}

void SpiderManager::SpawnSpider()
{
	sf::Vector2f pos;

	const bool leftSide = rand() % 2; //either left or right side, determined by a random number

	//for testing
#if false
	if (leftSide) //if its on the left side, then the x= 0
		pos.x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		pos.x = static_cast<float>(WindowManager::MainWindow.getSize().x);
#elif true
	pos.x = 0;
#endif
	pos.y = static_cast<float>(rand() % WindowManager::MainWindow.getSize().y); //anywhere on the y axis

	auto spider = SpiderFactory::GetSpider();
	spider->SpawnSpider(pos, this->spiderSpeed);
	ConsoleMsg::WriteLine("spider spawned");
}

void SpiderManager::RemoveSpider(Spider * const spider)
{
	SpiderFactory::RemoveSpider(spider);

	instance->SetAlarm(0, instance->timeToSpawn);
	ConsoleMsg::WriteLine("removed spider, setting alarm");
}

void SpiderManager::Alarm0()
{
	ConsoleMsg::WriteLine("alarm 0 reached");
	this->SpawnSpider();
}