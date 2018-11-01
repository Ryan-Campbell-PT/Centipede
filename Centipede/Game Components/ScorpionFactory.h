#ifndef SCORPIONFACTORY_H
#define SCORPIONFACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

class Scorpion;

class ScorpionFactory 
{
public:
	static Scorpion* GetScorpion();

	ScorpionFactory &operator=(const ScorpionFactory &c) = delete;
	ScorpionFactory(const ScorpionFactory &c) = delete;

	static void Terminate();
private:
	static ScorpionFactory* GetInstance();
	
	ScorpionFactory() = default;
	virtual ~ScorpionFactory() = default;	

	static ScorpionFactory* instance;
};

#endif //SCORPIONFACTORY_H