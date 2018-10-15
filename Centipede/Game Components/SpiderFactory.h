#ifndef SPIDER_FACTORY_H
#define SPIDER_FACTORY_H

#include "TEAL/CommonElements.h"

class Spider;

class SpiderFactory
{
public:
	static Spider* GetSpider();
	static void RemoveSpider(Spider * const spider);

private:
	static SpiderFactory *GetInstance();

	SpiderFactory() = default;
	virtual ~SpiderFactory() {};
	SpiderFactory &operator=(const SpiderFactory &c) = delete;
	SpiderFactory(const SpiderFactory &c) = delete;


	static SpiderFactory *instance;
};

#endif //SPIDER_FACTORY_H