#include "Centi_Poisoned.h"
#include "CentiMovement.h"

const CentipedeDirectionState * Centi_Poisoned::NextState(CentipedeHead * centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenUp;
}
