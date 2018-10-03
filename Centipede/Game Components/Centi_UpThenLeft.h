#ifndef CENTI_UP_THEN_LEFT
#define CENTI_UP_THEN_LEFT

#include "CentiMovement.h"

class Centipede;

class Centi_UpThenLeft : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos);
	virtual const CentipedeDirectionState* NextState();
	virtual void Initialize(CentipedeHead *centi) {};

private:
	Centipede * centi;
};

#endif // !CENTI_UP_THEN_LEFT
