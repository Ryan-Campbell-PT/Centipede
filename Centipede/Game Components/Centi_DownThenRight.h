#ifndef CENTI_DOWN_THEN_RIGHT
#define CENTI_DOWN_THEN_RIGHT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_DownThenRight : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override {};
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnDownEndRight; }

private:
};

#endif // !CENTI_DOWN_THEN_RIGHT
