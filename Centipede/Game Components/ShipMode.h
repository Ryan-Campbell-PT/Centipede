#ifndef SHIPMODE_H
#define SHIPMODE_H
#include <SFML/System/Vector2.hpp>

class PlayerInput;

class ShipMode
{
	//REMEMBER ALL CONST
public:
	virtual void MoveShip(sf::Vector2f &pos) {} ///this will be used for attractor mode
	virtual void MoveShip(PlayerInput *input) {} ///this will be used for playerinput

	static ShipMode* GetShipMode();
};

#endif // SHIPMODE_H
