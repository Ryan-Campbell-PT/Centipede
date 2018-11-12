#include "Centi_UpThenRight.h"
#include "CentipedeHead.h"

const CentipedeDirectionState * Centi_UpThenRight::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenUp;
}

const CentipedeDirectionState* Centi_UpThenRight::ExtraState(CentipedeHead* centi) const
{
	return &MoveSFM::rightThenDown;
}

void Centi_UpThenRight::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{
	yCounter += static_cast<int>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));
}
