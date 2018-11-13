#include "Centi_LeftThenDown.h"
#include "CentipedeHead.h"

const CentipedeDirectionState * Centi_LeftThenDown::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(270.f);
	return &MoveSFM::downThenRight;
}

const CentipedeDirectionState* Centi_LeftThenDown::ExtraState(CentipedeHead* centi) const
{
	centi->SetSpriteRotation(-90.f);
	return &MoveSFM::poisonedThenRight;
}

void Centi_LeftThenDown::CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const
{
	counter += static_cast<unsigned>(centi->GetSpeed());

	if (counter % SPRITE_SIZE == 0)
		centi->CheckGridAhead(sf::Vector2f(
			centi->GetPosition().x + this->GetOffsetArray().coloffset * SPRITE_SIZE,
			centi->GetPosition().y + this->GetOffsetArray().rowoffset * SPRITE_SIZE));
}
