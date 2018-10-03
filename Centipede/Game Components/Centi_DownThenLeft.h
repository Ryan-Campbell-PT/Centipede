#ifndef CENTI_DOWN_THEN_LEFT
#define CENTI_DOWN_THEN_LEFT

#include "CentiMovement.h"

class Centipede;

class Centi_DownThenLeft : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	Centipede * centi;
};

#endif // !CENTI_DOWN_THEN_LEFT
