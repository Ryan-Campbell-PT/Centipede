#include "Centi_DownThenLeft.h"
#include "CentipedeHead.h"

const CentipedeDirectionState * Centi_DownThenLeft::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenDown;
}

const CentipedeDirectionState* Centi_DownThenLeft::ExtraState(CentipedeHead* centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}

void Centi_DownThenLeft::CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const
{
	yCounter += static_cast<int>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));	
}
