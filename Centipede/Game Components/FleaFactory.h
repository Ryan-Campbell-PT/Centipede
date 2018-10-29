#ifndef FLEA_FACTORY_H
#define FLEA_FACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

class Flea;
class FleaManager;

class FleaFactory
{
public:
	static Flea* GetFlea();

	FleaFactory &operator=(const FleaFactory &c) = delete;
	FleaFactory(const FleaFactory &c) = delete;

private:
	static FleaFactory *GetInstance();

	FleaFactory() = default;
	virtual ~FleaFactory() { delete instance; };

	static FleaFactory * instance;
};

#endif //FLEA_FACTORY_H