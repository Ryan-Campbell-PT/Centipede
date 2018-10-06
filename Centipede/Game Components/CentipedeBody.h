#ifndef CENTIPEDEBODY_H
#define CENTIPEDEBODY_H

#include "TEAL/CommonElements.h"
#include <queue>
using std::queue;

class CentipedeHead;
enum class CentiMovementDirectionEnum;

class BS
{
public:
	BS() {};
	sf::Vector2f offset;
	CentiMovementDirectionEnum direction;
};


class CentipedeBody : public GameObject
{
public:
	///each bodypart should have a pointer to the head they will be following
	CentipedeBody(CentipedeHead * const head);
	CentipedeBody(CentipedeHead *const head, sf::Vector2f &const spawn, CentiMovementDirectionEnum direction);

	virtual ~CentipedeBody();
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;
	
	void UpdateBody(const float & x, const float & y);
	void AddOffset(sf::Vector2f const &offset, CentiMovementDirectionEnum direction);
	sf::Vector2f currentOffset;

private:
	virtual void Draw() override;
	virtual void Update() override;

	void ChangePos();

	CentiMovementDirectionEnum currentDirection;
	BS desired;
	std::queue<BS> offsetQueue;

	CentipedeHead * head;
	CentipedeBody *next, *prev; ///linked list of all the connected centiBodys

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;
};


#endif //CLASSNAME