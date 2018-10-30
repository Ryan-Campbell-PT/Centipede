#ifndef SHIP_AI_H
#define SHIP_AI_H

#include "ShipMode.h"

class Ship_Ai : public ShipMode
{
public:
	Ship_Ai();
	virtual void MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed) override;

private:
	bool up, left, down, right;
	float yTopBounds, yBottomBounds;
	float xLeftBounds, xRightBounds;
};

#endif // SHIP_AI_H
