#ifndef CENTI_RIGHT_THEN_DOWN
#define CENTI_RIGHT_THEN_DOWN

#include "CentiMovement.h"

class CentipedeHead;

class Centi_RightThenDown : public CentipedeDirectionState
{
public:
	Centi_RightThenDown();
	virtual void MoveDirection(sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState() const override;
	virtual void Initialize(CentipedeHead *centi) {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_RIGHT_THEN_DOWN
