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
	//CentipedeHead(const sf::Vector2f &pos, const int &numBodies);

	void InitializeHead(const sf::Vector2f & pos, const int &numBodies, CentipedeDirectionState const & direction);
	void InitializeHead(const sf::Vector2f & pos, CentipedeDirectionState const & direction);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Collide(GameObject * const go) {};
	virtual void Collide(Bullet * const bullet);

	sf::Vector2f GetPosition();
	void SetAnimationFrames(const int & startFrame, const int & endFrame);
	void CorrectXDirection();

	CentiMovementDirectionEnum GetCurrentMovementDirection();
	void CheckGridAhead(sf::Vector2f pos);
	void SetDirection(const CentipedeDirectionState * direction, bool centerToYPos);
	void SetSpriteRotation(const float &rotation);

	CentipedeDirectionState *GetDirection(CentiMovementDirectionEnum direction);

private:
	virtual ~CentipedeHead() {};
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