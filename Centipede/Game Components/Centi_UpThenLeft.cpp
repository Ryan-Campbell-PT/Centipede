#include "Centi_UpThenLeft.h"
#include "CentipedeHead.h"

const CentipedeDirectionState * Centi_UpThenLeft::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}

const CentipedeDirectionState* Centi_UpThenLeft::ExtraState(CentipedeHead* centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenDown;
}

void Centi_UpThenLeft::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{
	yCounter += static_cast<int>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));
}
