#ifndef SPIDER_FACTORY_H
#define SPIDER_FACTORY_H

#include "TEAL/CommonElements.h"

class Spider;

class SpiderFactory
{
public:
	static SpiderFactory *GetInstance();
	void SpawnSpider();

private:
	SpiderFactory();
	virtual ~SpiderFactory() { delete this->spider; };
	SpiderFactory &operator=(const SpiderFactory &c) = delete;
	SpiderFactory(const SpiderFactory &c) = delete;


	static SpiderFactory *instance;
	Spider* spider;

};

#endif //SPIDER_FACTORY_H