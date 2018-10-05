#ifndef SPIDER_FACTORY_H
#define SPIDER_FACTORY_H

#include "TEAL/CommonElements.h"

class Spider;

class SpiderFactory
{
public:
	static void SpawnSpider(sf::Vector2f &pos);
	static void RemoveSpider(Spider * const spider);

private:
	static SpiderFactory *GetInstance();

	SpiderFactory();
	virtual ~SpiderFactory() { delete this->spider; };
	SpiderFactory &operator=(const SpiderFactory &c) = delete;
	SpiderFactory(const SpiderFactory &c) = delete;


	static SpiderFactory *instance;
	Spider* spider;

};

#endif //SPIDER_FACTORY_H