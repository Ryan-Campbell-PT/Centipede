#ifndef SCORPIONFACTORY_H
#define SCORPIONFACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

#define SCORPIONSPAWN 25

class Scorpion;

class ScorpionFactory 
{
public:
	static ScorpionFactory* GetInstance();

	void SpawnScorpion();

private:
	ScorpionFactory();
	virtual ~ScorpionFactory();
	ScorpionFactory &operator=(const ScorpionFactory &c) = delete;
	ScorpionFactory(const ScorpionFactory &c) = delete;


	static ScorpionFactory* instance;
	Scorpion *scorpion;
};

#endif //SCORPIONFACTORY_H