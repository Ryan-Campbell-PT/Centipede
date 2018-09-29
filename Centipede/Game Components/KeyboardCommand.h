#ifndef KEYBOARD_COMMAND_H
#define KEYBOARD_COMMAND_H

#include "TEAL/CommonElements.h"

///this class is an interface for any command that will be used by the user
//todo: check whether this can be made a single class, or should be seperated

#if false
class KeyboardCommand
{
	KeyboardCommand(sf::Keyboard::Key k)
		:key(k) {}
public:
	virtual void SetCommand(sf::Keyboard::Key k) { this->key = k; }
	virtual sf::Keyboard::Key GetCommand() { return this->key; }

private:
	sf::Keyboard::Key key;
};

#elif true

class KeyboardCommand
{
public:
	virtual void SetCommand(sf::Keyboard::Key k) = 0;
	virtual sf::Keyboard::Key GetCommand() = 0;
};

#endif
#endif //KEYBOARD_COMMAND_H