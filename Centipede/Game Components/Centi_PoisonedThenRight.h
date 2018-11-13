#ifndef CENTI_POISONEDTHENRIGHT_H
#define CENTI_POISONEDTHENRIGHT_H

#include "CentipedeDirectionState.h"

class Centi_PoisonedThenRight : public CentipedeDirectionState
{
public:
	virtual ~Centi_PoisonedThenRight() = default;
	virtual const CentipedeDirectionState* NextState(CentipedeHead* centi) const override;
	virtual OffsetArray GetOffsetArray() const override;
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
};

#endif // CENTI_POISONEDTHENRIGHT_H
