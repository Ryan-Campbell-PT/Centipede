#include "SpiderFactory.h"

SpiderFactory *SpiderFactory::instance = 0;

SpiderFactory * SpiderFactory::GetInstance()
{
	if (SpiderFactory::instance == 0)
		SpiderFactory::instance = new SpiderFactory;

	return SpiderFactory::instance;
}
