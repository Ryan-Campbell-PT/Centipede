#ifndef CENTIPEDEBODY_H
#define CENTIPEDEBODY_H

#include "TEAL/CommonElements.h"
#include "AheadInformation.h"
#include "CentipedePart.h"

#include <queue>
using std::queue;

class CentipedeHead;
class Bullet;
enum class CentiMovementDirectionEnum;

class CentipedeBody : public GameObject, public CentipedePart
{
public:
	CentipedeBody();
	CentipedeBody(sf::Vector2f const &spawn, CentiMovementDirectionEnum direction);
	void InitializeBody(sf::Vector2f const& pos, CentiMovementDirectionEnum direction);

	virtual ~CentipedeBody() = default;
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;
	
	void UpdateBody(const float & x, const float & y);
	void AddOffset(sf::Vector2f const &offset, CentiMovementDirectionEnum direction);
	sf::Vector2f currentOffset;
	sf::Vector2f GetPosition();

	virtual void Collision(GameObject *g) override {};
	virtual void Collision(Bullet * bullet);
#if TESTER
	void SetBodyToHead();
#endif
	void RemoveBodyFromScreen(); ///this will handle sprite, active, and recycling
	//void RemoveBodyFromScreen(const bool& setBehindHead, const bool &spawnShroom);

private:
	virtual void Draw() override;
	virtual void Update() override;
	
	void ChangePos();

	CentiMovementDirectionEnum currentDirection;
	AheadInformation aheadTurningInformation;
	std::queue<AheadInformation> offsetQueue;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	bool active;
	unsigned int animationCounter;
};


#endif //CENTIPEDEBODY_H