#ifndef CENTI_RIGHT_THEN_UP
#define CENTI_RIGHT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_RightThenUp : public CentipedeDirectionState
{
public:
	Centi_RightThenUp();
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_RIGHT_THEN_UP
