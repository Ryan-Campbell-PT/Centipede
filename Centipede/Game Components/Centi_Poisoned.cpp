#include "Centi_Poisoned.h"
#include "CentiMovement.h"

void Centi_Poisoned::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{
	//MoveSFM::leftThenDown.GetOffsetArray()
	//todo
}

const CentipedeDirectionState * Centi_Poisoned::NextState(CentipedeHead * centi) const
{
	//centi->SetSpriteRotation(180.f);
	//return &MoveSFM::rightThenUp;
	return nullptr; ///todo
}

const CentipedeDirectionState * Centi_Poisoned::ExtraState(CentipedeHead * centi) const
{
	return nullptr;
}
