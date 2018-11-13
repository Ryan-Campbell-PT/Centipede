#include "Centi_PoisonedThenRight.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"

const CentipedeDirectionState * Centi_PoisonedThenRight::NextState(CentipedeHead * centi) const
{
	centi->SetSpriteRotation(180.f);
	return &MoveSFM::rightThenUp;
}

void Centi_PoisonedThenRight::CheckAhead(CentipedeHead * centi, unsigned & counter, unsigned & yCounter) const
{
	yCounter += static_cast<unsigned>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0)
	{
		centi->SetDirection(this);

		if(centi->GetPosition().y + SPRITE_SIZE > WindowManager::MainWindow.getSize().y)
			centi->SetDirection(this->NextState(centi));
	}
}

OffsetArray Centi_PoisonedThenRight::GetOffsetArray() const
{
	return MovementCollection::OffsetsPoisoned;
}
