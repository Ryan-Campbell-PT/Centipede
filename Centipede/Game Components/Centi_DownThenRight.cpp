#include "Centi_DownThenRight.h"
#include "CentipedeHead.h"

const CentipedeDirectionState * Centi_DownThenRight::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenDown;
}
void Centi_DownThenRight::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{	
	yCounter += static_cast<int>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0)
		centi->SetDirection(this->NextState(centi));
}
