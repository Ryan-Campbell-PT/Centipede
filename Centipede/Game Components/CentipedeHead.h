#ifndef CENTIHEAD_H
#define CENTIHEAD_H

#include "TEAL/CommonElements.h"

#define SPRITE_BEGIN 0
#define SPRITE_END 7
#define SPRITE_TURN_BEGIN 8
#define SPRITE_TURN_END 15

class CentipedeDirectionState;
class CentipedeBody;
enum class CentiMovementDirectionEnum;

class CentipedeHead : public GameObject
{
public:
	CentipedeHead(const sf::Vector2f &pos);
	virtual ~CentipedeHead() {};
	CentipedeHead &operator=(const CentipedeHead &c) = delete;
	CentipedeHead(const CentipedeHead &c) = delete;


	virtual void Update() override;
	virtual void Draw() override;

	sf::Vector2f GetPosition();
	void SetAnimationFrames(const int & startFrame, const int & endFrame);

	CentiMovementDirectionEnum GetCurrentMovementDirection();
	void CheckGridAhead(sf::Vector2f pos);
	void SetDirection(CentipedeDirectionState *direction);
	void SetSpriteRotation(const float &rotation);

private:
	///the state will determine what direction the centipede is going when spawned
	///this state is to reduce the number of if statements being checked, and just
	///going in the direction it needs to unless something happens
	CentipedeBody *bodys; ///linkedlist of all the bodys connected to it

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	CentipedeDirectionState * currentDirectionState;

	unsigned int animationCounter;
};

///this enum will be used so there is no need to delete movements throuhgout the game loop
enum class CentiMovementDirectionEnum
{
	Left,
	Right,
	Down,
	Up
};
#endif //CENTIHEAD_H