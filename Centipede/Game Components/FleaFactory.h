#ifndef FLEA_FACTORY_H
#define FLEA_FACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

#define SPAWN_FLEA_NUM 29

class Flea;

class FleaFactory : public Observee
{
public:
	static FleaFactory *GetInstance();
	void SpawnFlea();

	virtual void ObserverUpdate(int numShrooms) override;

private:
	FleaFactory();
	virtual ~FleaFactory() {};
	FleaFactory &operator=(const FleaFactory &c) = delete;
	FleaFactory(const FleaFactory &c) = delete;
	
	Flea *flea; //for now it is a single pointer, not sure if multiple flea can be on screen
	static FleaFactory * instance;
};

#endif //FLEA_FACTORY_H