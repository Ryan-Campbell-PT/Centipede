#ifndef BODY_UP
#define BODY_UP

#include "TEAL/CommonElements.h"
#include "CentiBodyDirection.h"

class Body_Up : public CentiBodyDirection
{
	virtual void MoveDirection(sf::Vector2f& pos) const override;
};

#endif //BODY_UP