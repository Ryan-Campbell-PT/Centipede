#ifndef CENTI_RIGHT_THEN_UP
#define CENTI_RIGHT_THEN_UP

#include "CentiMovement.h"

class CentipedeHead;

class Centi_RightThenUp : public CentipedeDirectionState
{
public:
	Centi_RightThenUp();
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override;
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;
		virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsStraightRight; }

private:
};

#endif // !CENTI_RIGHT_THEN_UP
