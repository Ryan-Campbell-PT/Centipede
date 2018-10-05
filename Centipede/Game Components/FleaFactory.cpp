#include "FleaFactory.h"
#include "Flea.h"
#include "FleaPool.h"

FleaFactory * FleaFactory::instance = 0;

FleaFactory::FleaFactory()
{
}

void FleaFactory::SpawnFlea(const FleaManager * const manager, sf::Vector2f const & pos)
{
	auto flea = FleaPool::GetFlea();

	if (flea == 0) //no fleas to recycle from. Create new flea
		flea = new Flea();

	flea->SpawnFlea(pos);
}

FleaFactory * FleaFactory::GetInstance()
{
	if (instance == 0)
		instance = new FleaFactory;

	return instance;
}
