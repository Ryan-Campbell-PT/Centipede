#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

class KeyboardCommand;

struct PlayerInput
{
	//all the avaliable commands a player can use
	KeyboardCommand *keyDown, *keyUp, *keyRight, *keyLeft, *keyFire;
};

#endif // PLAYERINPUT_H
