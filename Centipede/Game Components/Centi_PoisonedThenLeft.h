#ifndef CENTI_POISONEDTHENLEFT_H
#define CENTI_POISONEDTHENLEFT_H

#include "CentipedeDirectionState.h"

class Centi_PoisonedThenLeft : public CentipedeDirectionState
{
public:
	virtual ~Centi_PoisonedThenLeft() = default;
	virtual const CentipedeDirectionState* NextState(CentipedeHead* centi) const override;
	virtual OffsetArray GetOffsetArray() const override;
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
};

#endif // CENTI_POISONEDTHENLEFT_H
