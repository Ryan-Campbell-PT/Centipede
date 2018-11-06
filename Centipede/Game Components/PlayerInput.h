#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "KeyboardCommand.h"
#include "Ship_Left.h"
#include "Ship_Up.h"
#include "Ship_Right.h"
#include "Ship_Down.h"
#include "Ship_Fire.h"

class PlayerInput
{
public:
	//default player controls (but can still be overriden)
	PlayerInput()
		:keyDown(new Ship_Down(sf::Keyboard::S)),
		keyUp(new Ship_Up(sf::Keyboard::W)),
		keyRight(new Ship_Right(sf::Keyboard::D)),
		keyLeft(new Ship_Left(sf::Keyboard::A)),
		keyFire(new Ship_Fire(sf::Keyboard::Space))
	{}
	//all the avaliable commands a player can use
	KeyboardCommand *keyDown, *keyUp, *keyRight, *keyLeft, *keyFire;
};

#endif // PLAYERINPUT_H
