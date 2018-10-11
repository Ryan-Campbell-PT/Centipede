#ifndef CENTI_BODY_DIRECTION
#define CENTI_BODY_DIRECTION

#include "TEAL/CommonElements.h"


class CentiBodyDirection
{
public:
	virtual void MoveDirection(sf::Vector2f &pos) const{};
	virtual ~CentiBodyDirection() = default;
};

#endif //CENTI_BODY_DIRECTION