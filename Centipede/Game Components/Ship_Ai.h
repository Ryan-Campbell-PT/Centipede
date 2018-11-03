#ifndef SHIP_AI_H
#define SHIP_AI_H

#include "ShipMode.h"

class Ship_Ai : public ShipMode
{
public:
	Ship_Ai();
	~Ship_Ai() = default;
	virtual void MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed) override;
	virtual void MushroomCollision(const PlayerInput * input, sf::Vector2f &pos, const float &speed) override;

private:
	bool up, left, down, right, stop;
	float yTopBounds, yBottomBounds;
	float xLeftBounds, xRightBounds;
	unsigned int stopCounter;
	int randomNum;
};

#endif // SHIP_AI_H
