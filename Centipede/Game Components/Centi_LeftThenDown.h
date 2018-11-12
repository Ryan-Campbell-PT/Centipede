#ifndef CENTI_LEFT_THEN_DOWN
#define CENTI_LEFT_THEN_DOWN

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenDown : public CentipedeDirectionState
{
public:
	Centi_LeftThenDown();
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override;
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsStraightLeft; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const override;

private:
};

#endif // !CENTI_LEFT_THEN_DOWN
