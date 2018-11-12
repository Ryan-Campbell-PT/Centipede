#ifndef CENTI_DOWN_THEN_RIGHT
#define CENTI_DOWN_THEN_RIGHT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_DownThenRight : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnDownEndRight; }
	virtual void CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const override;
};

#endif // !CENTI_DOWN_THEN_RIGHT
