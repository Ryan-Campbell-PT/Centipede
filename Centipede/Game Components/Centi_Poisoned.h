#ifndef CENTI_POISONED
#define CENTI_POISONED

#include "TEAL/CommonElements.h"
#include "CentipedeDirectionState.h"

class CentipedeHead;

class Centi_Poisoned : public CentipedeDirectionState
{
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const override;

};
#endif //CENTI_POISONED