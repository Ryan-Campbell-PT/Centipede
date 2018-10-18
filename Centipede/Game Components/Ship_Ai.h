#ifndef SHIP_AI_H
#define SHIP_AI_H

#include "ShipMode.h"

class Ship_Ai : public ShipMode
{
public:
	virtual void MoveShip(sf::Vector2f &pos) override;

};

#endif // SHIP_AI_H
