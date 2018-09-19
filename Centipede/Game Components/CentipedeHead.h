#ifndef CENTIHEAD_H
#define CENTIHEAD_H

#include "TEAL/CommonElements.h"

class CentipedeDirectionState;
class CentipedeBody;

class CentipedeHead : public GameObject
{
public:
	CentipedeHead(const sf::Vector2f &pos);
	virtual ~CentipedeHead() {};
	CentipedeHead &operator=(const CentipedeHead &c);
	CentipedeHead(const CentipedeHead &c);

private:
	///the state will determine what direction the centipede is going when spawned
	///this state is to reduce the number of if statements being checked, and just
	///going in the direction it needs to unless something happens
	CentipedeDirectionState * currentDirectionState;
	CentipedeBody *bodys; ///linkedlist of all the bodys connected to it

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif //CENTIHEAD_H