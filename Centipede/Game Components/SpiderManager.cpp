#include "SpiderManager.h"
#include "SpiderPool.h"
#include "SpiderFactory.h"
#include <random>

SpiderManager* SpiderManager::instance = 0;

SpiderManager * SpiderManager::GetInstance()
{
	if (instance == 0)
		instance = new SpiderManager;

	return instance;
}

void SpiderManager::SpawnSpider()
{
	sf::Vector2f pos;

	bool leftSide = rand() % 2; //either left or right side, determined by a random number

	if (leftSide) //if its on the left side, then the x= 0
		pos.x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		pos.x = static_cast<float>(WindowManager::MainWindow.getSize().x);

	pos.y = static_cast<float>(rand() % WindowManager::MainWindow.getSize().y); //anywhere on the y axis

	SpiderFactory::SpawnSpider(pos);
}

void SpiderManager::RemoveSpider(Spider * const spider)
{
	SpiderFactory::RemoveSpider(spider);
}
