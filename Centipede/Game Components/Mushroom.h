#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "TEAL/GameObject.h"
//#include "TEAL/CommonElements.h"

class Mushroom : public GameObject
{
public:
	friend class MushroomFactory;

	bool SetPosition(sf::Vector2f v);

private:
	Mushroom(sf::Vector2f v);
	~Mushroom();
	Mushroom &operator=(const Mushroom &c) = delete;
	Mushroom(const Mushroom &c) = delete;

};

#endif //MUSHROOM_H