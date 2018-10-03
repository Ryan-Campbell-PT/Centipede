#ifndef CENTI_DOWN_THEN_RIGHT
#define CENTI_DOWN_THEN_RIGHT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_DownThenRight : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_DOWN_THEN_RIGHT
