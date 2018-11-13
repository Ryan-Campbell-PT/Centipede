#include "Centi_PoisonedThenLeft.h"
#include "CentipedeHead.h"
#include "GameGrid.h"
#include "CentiMovement.h"

const CentipedeDirectionState * Centi_PoisonedThenLeft::NextState(CentipedeHead * centi) const
{
	centi->SetSpriteRotation(0.f);
	return &MoveSFM::leftThenUp;
}

void Centi_PoisonedThenLeft::CheckAhead(CentipedeHead * centi, unsigned & counter, unsigned & yCounter) const
{
	yCounter += static_cast<unsigned>(centi->GetSpeed());

	if(yCounter % SPRITE_SIZE == 0 && centi->GetPosition().y + SPRITE_SIZE > WindowManager::MainWindow.getSize().y)
		centi->SetDirection(this->NextState(centi));
}

OffsetArray Centi_PoisonedThenLeft::GetOffsetArray() const
{
	return MovementCollection::OffsetsPoisoned;
}
