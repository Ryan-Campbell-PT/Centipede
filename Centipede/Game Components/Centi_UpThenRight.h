#ifndef CENTI_UP_THEN_RIGHT
#define CENTI_UP_THEN_RIGHT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_UpThenRight : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override {};
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnUpEndRight; }

private:
};

#endif // !CENTI_UP_THEN_RIGHT
