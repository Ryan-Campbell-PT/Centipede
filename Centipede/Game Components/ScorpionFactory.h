#ifndef SCORPIONFACTORY_H
#define SCORPIONFACTORY_H

#include "TEAL/CommonElements.h"
#include "Observee.h"

#define SCORPIONSPAWN 25

class Scorpion;

class ScorpionFactory 
{
public:
	static void SpawnScorpion(sf::Vector2f pos);
	static void RemoveScorpion(Scorpion * const scorpion);

	ScorpionFactory &operator=(const ScorpionFactory &c) = delete;
	ScorpionFactory(const ScorpionFactory &c) = delete;

private:
	static ScorpionFactory* GetInstance();
	
	ScorpionFactory();
	virtual ~ScorpionFactory();	

	static ScorpionFactory* instance;
};

#endif //SCORPIONFACTORY_H