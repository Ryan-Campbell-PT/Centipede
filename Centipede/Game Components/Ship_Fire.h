#ifndef SHIP_FIRE_H
#define SHIP_FIRE_H

#include "KeyboardCommand.h"

class Ship_Fire : public KeyboardCommand
{
public:
	Ship_Fire(sf::Keyboard::Key k)
		:key(k) {}
	virtual void SetCommand(sf::Keyboard::Key k) override { this->key = k; };
	virtual sf::Keyboard::Key GetCommand() override { return this->key; };

private:
	sf::Keyboard::Key key;

};

#endif //SHIP_FIRE_H