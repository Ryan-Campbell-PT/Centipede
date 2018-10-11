#include "Centi_Poisoned.h"
#include "CentiMovement.h"

void Centi_Poisoned::MoveDirection(CentipedeHead * centi, sf::Vector2f & pos) const
{
	pos.y += CENTI_SPEED;

	if(pos.y + SPRITE_SIZE > WindowManager::MainWindow.getSize().y)
		centi->CheckGridAhead(pos);
}

const CentipedeDirectionState * Centi_Poisoned::NextState(CentipedeHead * centi) const
{
	centi->SetSpriteRotation(180.f);
	centi->CenterOnY();
	return &MoveSFM::rightThenUp;
}
