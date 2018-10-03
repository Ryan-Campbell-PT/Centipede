#ifndef CENTI_DOWN_THEN_RIGHT
#define CENTI_DOWN_THEN_RIGHT

#include "CentiMovement.h"

class Centipede;

class Centi_DownThenRight : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
	virtual void NextState() = 0;
	virtual void Initialize(CentipedeHead *centi) {};

private:
	Centipede * centi;
};

#endif // !CENTI_DOWN_THEN_RIGHT
