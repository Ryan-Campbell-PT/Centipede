#ifndef CENTI_DOWN_THEN_LEFT
#define CENTI_DOWN_THEN_LEFT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_DownThenLeft : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState(CentipedeHead *centi) const override;
	virtual void Initialize(CentipedeHead *centi) const override {};
	virtual CentiMovementDirectionEnum GetDirectionEnum() const override;
	virtual OffsetArray GetOffsetArray() const override { return MovementCollection::OffsetsTurnDownEndLeft; };
	virtual void CheckAhead(CentipedeHead* centi, unsigned int &counter, unsigned int &yCounter) const override;

private:
};

#endif // !CENTI_DOWN_THEN_LEFT
