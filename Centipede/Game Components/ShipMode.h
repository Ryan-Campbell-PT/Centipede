#ifndef SHIPMODE_H
#define SHIPMODE_H
#include <SFML/System/Vector2.hpp>

class ShipMode
{
	//REMEMBER ALL CONST
public:
	virtual void MoveShip(sf::Vector2f &pos) = 0;
};

#endif // SHIPMODE_H
