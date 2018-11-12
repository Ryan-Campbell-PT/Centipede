#ifndef CENTI_UP_THEN_RIGHT
#define CENTI_UP_THEN_RIGHT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_UpThenRight : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual const CentipedeDirectionState* ExtraState(CentipedeHead *centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnUpEndRight; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
};

#endif // !CENTI_UP_THEN_RIGHT
