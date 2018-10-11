#ifndef BODY_RIGHT
#define BODY_RIGHT

#include "TEAL/CommonElements.h"
#include "CentiBodyDirection.h"

class Body_Right : public CentiBodyDirection
{
	virtual void MoveDirection(sf::Vector2f& pos) const override;
};

#endif //BODY_RIGHT