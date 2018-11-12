#ifndef CENTI_LEFT_THEN_DOWN
#define CENTI_LEFT_THEN_DOWN

#include "CentiMovement.h"

class CentipedeHead;

class Centi_LeftThenDown : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsStraightLeft; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const override;
};

#endif // !CENTI_LEFT_THEN_DOWN
