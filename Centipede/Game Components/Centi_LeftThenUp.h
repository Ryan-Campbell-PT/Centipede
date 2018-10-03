#ifndef CENTI_LEFT_THEN_UP
#define CENTI_LEFT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenUp : public CentipedeDirectionState
{
public:
	Centi_LeftThenUp();
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_LEFT_THEN_UP
