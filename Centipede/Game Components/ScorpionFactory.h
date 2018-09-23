#ifndef SCORPIONFACTORY_H
#define SCORPIONFACTORY_H

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionFactory
{
public:
	static ScorpionFactory* GetInstance();

private:
	ScorpionFactory();
	virtual ~ScorpionFactory();
	ScorpionFactory &operator=(const ScorpionFactory &c) = delete;
	ScorpionFactory(const ScorpionFactory &c) = delete;

	void SpawnScorpion(sf::Vector2f &pos);

	static ScorpionFactory* instance;
	Scorpion *scorpion;
};

#endif //SCORPIONFACTORY_H