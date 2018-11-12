#ifndef CENTI_DOWN_THEN_LEFT
#define CENTI_DOWN_THEN_LEFT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_DownThenLeft : public CentipedeDirectionState
{
public:
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual const CentipedeDirectionState* ExtraState(CentipedeHead *centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnDownEndLeft; };
	virtual void CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const override;
};

#endif // !CENTI_DOWN_THEN_LEFT
