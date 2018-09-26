#ifndef CENTIPEDEBODY_H
#define CENTIPEDEBODY_H

#include "TEAL/CommonElements.h"

class CentipedeHead;

class CentipedeBody : public GameObject
{
public:
	///each bodypart should have a pointer to the head they will be following
	CentipedeBody(const CentipedeHead *head);
	virtual ~CentipedeBody();
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;

private:
	CentipedeHead * head;
	CentipedeBody *next, *prev; ///linked list of all the connected centiBodys

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif //CLASSNAME