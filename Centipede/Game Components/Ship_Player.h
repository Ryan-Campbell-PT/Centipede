#ifndef SHIP_PLAYER_H
#define SHIP_PLAYER_H

#include "ShipMode.h"

class Ship_Player : public ShipMode
{
public:
	virtual void MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed) override;

};

#endif // SHIP_PLAYER_H
