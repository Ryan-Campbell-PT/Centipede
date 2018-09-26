#include "SpiderFactory.h"
#include "Spider.h"

#include <random>

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

void SpiderFactory::SpawnSpider()
{
	sf::Vector2f pos;
	
	bool leftSide = rand() % 2; //either left or right side, determined by a random number

	if (leftSide) //if its on the left side, then the x= 0
		pos.x = 0;

	else //otherwise its on the right, and it goes to the max x distance
		pos.x = WindowManager::MainWindow.getSize().x;

	pos.y = rand() % WindowManager::MainWindow.getSize().y; //anywhere on the y axis
	
	GetInstance()->spider->SpawnSpider(pos);
}

void SpiderFactory::InitializeSpider()
{
	GetInstance();
}
