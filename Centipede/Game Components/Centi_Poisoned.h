#ifndef CENTI_POISONED
#define CENTI_POISONED

#include "TEAL/CommonElements.h"
#include "CentipedeDirectionState.h"

class CentipedeHead;

class Centi_Poisoned : public CentipedeDirectionState
{
	virtual void CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const override;
	virtual const CentipedeDirectionState* ExtraState(CentipedeHead * centi) const override;
	virtual OffsetArray GetOffsetArray() const override { return {0, 1}; }

};
#endif //CENTI_POISONED