#ifndef SHIPMODE_H
#define SHIPMODE_H
#include <SFML/System/Vector2.hpp>

class PlayerInput;

class ShipMode
{
	//REMEMBER ALL CONST
public:
	virtual void MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed) {} ///this will be used for attractor mode
	//virtual void MoveShip() {} ///this will be used for playerinput

	//static ShipMode* GetShipMode();
};

#endif // SHIPMODE_H
