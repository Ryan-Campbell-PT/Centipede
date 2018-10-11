#ifndef BODY_LEFT
#define BODY_LEFT

#include "TEAL/CommonElements.h"
#include "CentiBodyDirection.h"

class Body_Left : public CentiBodyDirection
{
	virtual void MoveDirection(sf::Vector2f& pos) const override;
};

#endif //BODY_LEFT