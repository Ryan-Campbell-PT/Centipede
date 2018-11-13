#ifndef CENTI_RIGHT_THEN_UP
#define CENTI_RIGHT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_RightThenUp : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const override;
	virtual const CentipedeDirectionState* ExtraState(CentipedeHead* centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsStraightRight; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
};

#endif // !CENTI_RIGHT_THEN_UP
