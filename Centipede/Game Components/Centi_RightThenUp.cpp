#include "Centi_RightThenUp.h"
#include "CentipedeHead.h"

const CentipedeDirectionState* Centi_RightThenUp::NextState(CentipedeHead *centi) const
{
	centi->SetSpriteRotation(90.f);
	return &MoveSFM::upThenLeft;
}

const CentipedeDirectionState* Centi_RightThenUp::ExtraState(CentipedeHead* centi) const
{
	centi->SetSpriteRotation(-90.f);
	return &MoveSFM::poisonedThenRight;
}

void Centi_RightThenUp::CheckAhead(CentipedeHead* centi, unsigned& counter, unsigned& yCounter) const
{
	counter += static_cast<unsigned>(centi->GetSpeed());

	if (counter % SPRITE_SIZE == 0)
		centi->CheckGridAhead(sf::Vector2f(
			centi->GetPosition().x + this->GetOffsetArray().coloffset * SPRITE_SIZE,
			centi->GetPosition().y + this->GetOffsetArray().rowoffset * SPRITE_SIZE));
}
