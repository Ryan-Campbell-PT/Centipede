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
	SetTimer();
}

void SpiderManager::DeInitializeSpider()
{
	GetInstance()->active = false;
	instance->AlarmCancel(0);
}

void SpiderManager::SpawnSpider()
{
	if(GetInstance()->active)
		return;

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
	GetInstance()->active = true;
}

void SpiderManager::RemoveSpider(Spider * const spider)
{
	GetInstance()->active = false;
}

void SpiderManager::SetTimer()
{
	GetInstance()->SetAlarm(0, static_cast<float>(rand() % static_cast<int>(ceil(instance->timeToSpawn))));
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

SpiderManager::SpiderManager()
	:spiderSpeed(1.5f), timeToSpawn(4)
{
}

void SpiderManager::Alarm0()
{
	this->SpawnSpider();
}