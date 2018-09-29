#ifndef SHIP_UP_H
#define SHIP_UP_H

#include "KeyboardCommand.h"

class Ship_Up : public KeyboardCommand
{
public:
	Ship_Up(sf::Keyboard::Key k)
		:key(k) {}
	virtual void SetCommand(sf::Keyboard::Key k) override { this->key = k; }
	virtual sf::Keyboard::Key GetCommand() override { return this->key; }

private:
	sf::Keyboard::Key key;

};
#endif //SHIP_UP_H