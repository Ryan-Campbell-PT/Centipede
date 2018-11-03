#ifndef SHIPMODE_H
#define SHIPMODE_H
#include <SFML/System/Vector2.hpp>

class PlayerInput;

class ShipMode
{
public:
	virtual ~ShipMode() = default;
	virtual void MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed) {} ///this will be used for attractor mode
	virtual void MushroomCollision(const PlayerInput * input, sf::Vector2f &pos, const float &speed) {}
};
#endif // SHIPMODE_H
