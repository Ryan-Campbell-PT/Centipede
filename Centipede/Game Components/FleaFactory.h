#ifndef FLEA_FACTORY_H
#define FLEA_FACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

class Flea;
class FleaManager;

class FleaFactory
{
public:
	///will talk with the FleaPool to get a flea that can be spawned
	///and will spawn a flea in that location
	///the manager is just to confirm only the manager is spawning the flea
	static void SpawnFlea(const FleaManager * const manager, sf::Vector2f const &pos);

private:
	static FleaFactory *GetInstance();
	
	FleaFactory();
	virtual ~FleaFactory() {};
	FleaFactory &operator=(const FleaFactory &c) = delete;
	FleaFactory(const FleaFactory &c) = delete;
	
	static FleaFactory * instance;
};

#endif //FLEA_FACTORY_H