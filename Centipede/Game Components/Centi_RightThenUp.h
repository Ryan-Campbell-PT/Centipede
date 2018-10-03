#ifndef CENTI_RIGHT_THEN_UP
#define CENTI_RIGHT_THEN_UP

#include "CentiMovement.h"

class Centipede;

class Centi_RightThenUp : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
	virtual void NextState() = 0;
	virtual void Initialize(CentipedeHead *centi) {};

private:
	Centipede * centi;
};

#endif // !CENTI_RIGHT_THEN_UP
