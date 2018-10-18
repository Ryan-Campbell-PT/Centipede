#ifndef SHIP_PLAYER_H
#define SHIP_PLAYER_H

#include "ShipMode.h"

class Ship_Player : public ShipMode
{
public:
	virtual void MoveShip(sf::Vector2f &pos) override;

};

#endif // SHIP_PLAYER_H
