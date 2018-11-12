#ifndef CENTI_POISONED
#define CENTI_POISONED

#include "TEAL/CommonElements.h"
#include "CentipedeDirectionState.h"

class CentipedeHead;

class Centi_Poisoned : public CentipedeDirectionState
{
//todo
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const override;

};
#endif //CENTI_POISONED