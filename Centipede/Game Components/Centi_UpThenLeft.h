#ifndef CENTI_UP_THEN_LEFT
#define CENTI_UP_THEN_LEFT

#include "CentiMovement.h"

class CentipedeHead;

class Centi_UpThenLeft : public CentipedeDirectionState
{
public:
	virtual void MoveDirection(sf::Vector2f &pos) const override;
	virtual const CentipedeDirectionState* NextState() const override;
	virtual void Initialize(CentipedeHead *centi) const override {};

private:
	CentipedeHead * centi;
};

#endif // !CENTI_UP_THEN_LEFT
