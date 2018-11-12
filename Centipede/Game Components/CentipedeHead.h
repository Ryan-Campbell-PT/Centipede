#ifndef CENTIHEAD_H
#define CENTIHEAD_H

#include "TEAL/CommonElements.h"
#include "CentipedePart.h"
#include "MovementCollection.h"
#include "ScoreCmd.h"

#define SPRITE_BEGIN 0
#define SPRITE_END 7
#define SPRITE_TURN_BEGIN 8
#define SPRITE_TURN_END 15
#define DIRECTION_SIZE sizeof(CentiMovementDirectionEnum)

class Ship;
class CentipedeDirectionState;
class CentipedeBody;
enum class CentiMovementDirectionEnum;
class GameObject;
class Bullet;

class CentipedeHead : public GameObject, public CentipedePart
{
public:
	CentipedeHead();
	virtual ~CentipedeHead();
	CentipedeHead &operator=(const CentipedeHead &c) = delete;
	CentipedeHead(const CentipedeHead &c) = delete;

	///this initilization will be used for completely new heads
	void InitializeHead(sf::Vector2f & pos, const int &numBodies, CentipedeDirectionState const & direction);
	///while this will be used when turning a body into a head
	///all the links are already defined, we just need to get the right direction to go, and where to start
	///the boolean is meant for whether the centipede itself should determine its direction, or if an outside source will handle that
	void InitializeHead(const sf::Vector2f & pos, CentipedeDirectionState const & direction, const bool &setDirection = true);
	//todo: speed not currenly in the api
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual void Alarm0() override;

	void SetAnimationFrames(const int & startFrame, const int & endFrame);

	void CheckGridAhead(sf::Vector2f pos);
	void SetDirection(const CentipedeDirectionState * direction);
	void SetSpriteRotation(const float &rotation);

	///this function translates from an enum to pointer
	CentipedeDirectionState *GetDirection(CentiMovementDirectionEnum direction);
	const CentipedeDirectionState *GetDirection(); ///this simply get the current direction
	CentiMovementDirectionEnum GetDirectionEnum(); ///this is the direction, but tranfered to enum

	virtual void Collision(GameObject *) override {}
	virtual void Collision(Bullet *);

	sf::Vector2f GetPosition() { return this->position; }
	void SetSpeed(const int speed);
	float GetSpeed() { return speed; }
	bool GetConcent() const { return concent; }

private:
	///this function will apply the number of bodies connected to the head, at the creation of the head
	void SetupBodies(OffsetArray direction, int numBodies);

	//void RemoveHead();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	const CentipedeDirectionState *currentDirectionState;
	const CentipedeDirectionState *prevDirection;

	std::vector<CentipedeDirectionState*> directionArray;

	unsigned int animationCounter;
	float speed;

	unsigned int yCounter;
	ScoreCmd* pDeath;

	///this variable is work around to allow the waves to progress
	bool concent;

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