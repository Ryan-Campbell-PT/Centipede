#include "SpiderManager.h"
#include "Spider.h"
#include "SpiderFactory.h"
#include <random>

SpiderManager* SpiderManager::instance = nullptr;

SpiderManager * SpiderManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SpiderManager;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void SpiderManager::InitializeSpider(const float timeToSpawn, const float spiderSpeed)
{
	GetInstance()->spiderSpeed = spiderSpeed;

	instance->timeToSpawn = timeToSpawn;
	instance->SetAlarm(0, timeToSpawn);
}

void SpiderManager::DeInitializeSpider()
{
	GetInstance()->active = false;
	instance->AlarmCancel(0);
}

void SpiderManager::SpawnSpider()
{
	sf::Vector2f pos;

	const bool leftSide = rand() % 2; //either left or right side, determined by a random number

	//for testing
	if (leftSide) //if its on the left side, then the x= 0
		pos.x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		pos.x = static_cast<float>(WindowManager::MainWindow.getSize().x);

	pos.y = static_cast<float>(rand() % WindowManager::MainWindow.getSize().y); //anywhere on the y axis

	auto spider = SpiderFactory::GetSpider();
	spider->SpawnSpider(pos, this->spiderSpeed);

}

void SpiderManager::RemoveSpider(Spider * const spider)
{
	SpiderFactory::RemoveSpider(spider);
}

void SpiderManager::SetTimer()
{
	GetInstance()->SetAlarm(0, instance->timeToSpawn);
}

void SpiderManager::EndWave()
{

}

void SpiderManager::Terminate(GameObject *)
{
	delete instance;
	instance = nullptr;

	SpiderFactory::Terminate();
}

void SpiderManager::Alarm0()
{
	this->SpawnSpider();
}