#include "Centi_RightThenDown.h"
#include "CentipedeHead.h"


const CentipedeDirectionState * Centi_RightThenDown::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(270.f);
	return &MoveSFM::downThenLeft;
}

const CentipedeDirectionState* Centi_RightThenDown::ExtraState(CentipedeHead* centi) const
{
	centi->SetSpriteRotation(-90.f);
	return &MoveSFM::poisonedThenLeft;
}

void Centi_RightThenDown::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{
	counter += static_cast<unsigned>(centi->GetSpeed());

	if (counter % SPRITE_SIZE == 0)
		centi->CheckGridAhead(sf::Vector2f(
			centi->GetPosition().x + this->GetOffsetArray().coloffset * SPRITE_SIZE,
			centi->GetPosition().y + this->GetOffsetArray().rowoffset * SPRITE_SIZE));
}
