#ifndef CENTI_RIGHT_THEN_DOWN
#define CENTI_RIGHT_THEN_DOWN

#include "CentiMovement.h"

class CentipedeHead;

class Centi_RightThenDown : public CentipedeDirectionState
{
public:
	Centi_RightThenDown();
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override;
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;

private:
};

#endif // !CENTI_RIGHT_THEN_DOWN
