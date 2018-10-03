#ifndef CENTI_LEFT_THEN_UP
#define CENTI_LEFT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenUp : public CentipedeDirectionState
{
public:
	Centi_LeftThenUp();
	virtual void MoveDirection(sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState() const override;
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_LEFT_THEN_UP
