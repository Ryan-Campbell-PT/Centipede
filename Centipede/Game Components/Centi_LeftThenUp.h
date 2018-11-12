#ifndef CENTI_LEFT_THEN_UP
#define CENTI_LEFT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenUp : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsStraightLeft; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
};

#endif // !CENTI_LEFT_THEN_UP
