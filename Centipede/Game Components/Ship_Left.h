#ifndef SHIP_LEFT_H
#define SHIP_LEFT_H


#include "KeyboardCommand.h"

class Ship_Left : public KeyboardCommand
{
public:
	Ship_Left(sf::Keyboard::Key k)
	:key(k) {}
	virtual void SetCommand(sf::Keyboard::Key k) override { this->key = k; }
	virtual sf::Keyboard::Key GetCommand() override { return this->key; }

private:
	sf::Keyboard::Key key;

};

#endif //SHIP_LEFT_H