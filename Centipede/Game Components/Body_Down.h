#ifndef BODY_DOWN
#define BODY_DOWN

#include "TEAL/CommonElements.h"
#include "CentiBodyDirection.h"

class Body_Down : public CentiBodyDirection
{
	virtual void MoveDirection(sf::Vector2f& pos) const override;
};

#endif //BODY_DOWN