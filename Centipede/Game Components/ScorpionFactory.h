#ifndef SCORPIONFACTORY_H
#define SCORPIONFACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

#define SCORPIONSPAWN 25

class Scorpion;

class ScorpionFactory : public Observee
{
public:
	static ScorpionFactory* GetInstance();

	virtual void ObserverUpdate(int numShrooms) override;

private:
	ScorpionFactory();
	virtual ~ScorpionFactory();
	ScorpionFactory &operator=(const ScorpionFactory &c) = delete;
	ScorpionFactory(const ScorpionFactory &c) = delete;

	void SpawnScorpion();

	static ScorpionFactory* instance;
	Scorpion *scorpion;
};

#endif //SCORPIONFACTORY_H