#ifndef SPIDER_FACTORY_H
#define SPIDER_FACTORY_H

#include "TEAL/CommonElements.h"

class Spider;

class SpiderFactory
{
public:
	static Spider* GetSpider();
	static void RemoveSpider(Spider * const spider);

	SpiderFactory &operator=(const SpiderFactory &c) = delete;
	SpiderFactory(const SpiderFactory &c) = delete;

	static void Terminate();
private:
	static SpiderFactory *GetInstance();

	SpiderFactory() = default;
	virtual ~SpiderFactory() = default;
	

	static SpiderFactory *instance;
};

#endif //SPIDER_FACTORY_H