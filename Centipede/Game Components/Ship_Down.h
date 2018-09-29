#ifndef SHIP_DOWN_H
#define SHIP_DOWN_H

#include "KeyboardCommand.h"

class Ship_Down : public KeyboardCommand
{
public:
	Ship_Down(sf::Keyboard::Key k)
	:key(k) {}
	virtual void SetCommand(sf::Keyboard::Key k) override { this->key = k; }
	virtual sf::Keyboard::Key GetCommand() override { return this->key; }

private:
	sf::Keyboard::Key key;
};
#endif //SHIP_DOWN_H