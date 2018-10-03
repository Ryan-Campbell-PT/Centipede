#ifndef CENTI_LEFT_THEN_DOWN
#define CENTI_LEFT_THEN_DOWN

#include "CentiMovement.h"

class Centipede;

class Centi_LeftThenDown : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
	virtual void NextState() = 0;
	virtual void Initialize(CentipedeHead *centi) {};

private:
	Centipede * centi;
};

#endif // !CENTI_LEFT_THEN_DOWN
