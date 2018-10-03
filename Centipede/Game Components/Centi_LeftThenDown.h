#ifndef CENTI_LEFT_THEN_DOWN
#define CENTI_LEFT_THEN_DOWN

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenDown : public CentipedeDirectionState
{
public:
	Centi_LeftThenDown();
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_LEFT_THEN_DOWN
