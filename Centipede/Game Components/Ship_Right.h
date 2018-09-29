#ifndef SHIP_RIGHT_H
#define SHIP_RIGHT_H

#include "KeyboardCommand.h"

class Ship_Right : public KeyboardCommand
{
public:
	Ship_Right(sf::Keyboard::Key k)
		:key(k) {}
	virtual void SetCommand(sf::Keyboard::Key k) override { this->key = k; }
	virtual sf::Keyboard::Key GetCommand() override { return this->key; }

private:
	sf::Keyboard::Key key;
};


#endif //SHIP_RIGHT_H