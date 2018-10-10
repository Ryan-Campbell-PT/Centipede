#ifndef CENTIHEAD_H
#define CENTIHEAD_H

#include "TEAL/CommonElements.h"
#include "CentipedePart.h"

#define SPRITE_BEGIN 0
#define SPRITE_END 7
#define SPRITE_TURN_BEGIN 8
#define SPRITE_TURN_END 15
#define DIRECTION_SIZE sizeof(CentiMovementDirectionEnum)

class CentipedeDirectionState;
class CentipedeBody;
enum class CentiMovementDirectionEnum;
class GameObject;
class Bullet;

class CentipedeHead : public GameObject, public CentipedePart
{
public:
	CentipedeHead();
	///this initilization will be used for completely new heads
	void InitializeHead(const sf::Vector2f & pos, const int &numBodies, CentipedeDirectionState const & direction);
	///while this will be used when turning a body into a head
	///all the links are already defined, we just need to get the right direction to go, and where to start
	///the boolean is meant for whether the centipede itself should determine its direction, or if an outside source will handle that
	void InitializeHead(const sf::Vector2f & pos, CentipedeDirectionState const & direction, const bool &setDirection = true);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Collide(GameObject * const go) {};
	virtual void Collide(Bullet * const bullet);

	sf::Vector2f GetPosition();
	void SetAnimationFrames(const int & startFrame, const int & endFrame);
	void CorrectXDirection();

	void CheckGridAhead(sf::Vector2f pos);
	void SetDirection(const CentipedeDirectionState * direction, bool centerToYPos);
	void SetSpriteRotation(const float &rotation);

	///this function translates from an enum to pointer
	CentipedeDirectionState *GetDirection(CentiMovementDirectionEnum direction);
	const CentipedeDirectionState *GetDirection(); ///this simply get the current direction
	CentiMovementDirectionEnum GetDirectionEnum(); ///this is the direction, but tranfered to enum

private:
	virtual ~CentipedeHead() = default;
	CentipedeHead &operator=(const CentipedeHead &c) = delete;
	CentipedeHead(const CentipedeHead &c) = delete;
	///this function will apply the number of bodies connected to the head, at the creation of the head
	void SetupBodies(CentiMovementDirectionEnum direction, const int &numBodies);
	
	void RemoveHead();

	///the state will determine what direction the centipede is going when spawned
	///this state is to reduce the number of if statements being checked, and just
	///going in the direction it needs to unless something happens
	CentipedeBody *bodies; ///linkedlist of all the bodys connected to it

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	const CentipedeDirectionState *currentDirectionState;
	std::vector<CentipedeDirectionState*> directionArray;

	unsigned int animationCounter;

	bool active;
};

///this enum will be used so there is no need to delete movements throuhgout the game loop
enum class CentiMovementDirectionEnum
{
	Error = -1,
	Left = 0,
	Right = 1,
	Down = 2,
	Up = 3
};
#endif //CENTIHEAD_H