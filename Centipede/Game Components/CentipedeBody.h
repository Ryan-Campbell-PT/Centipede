#ifndef CENTIPEDEBODY_H
#define CENTIPEDEBODY_H

#include "TEAL/CommonElements.h"
#include "AheadInformation.h"
#include "CentipedePart.h"

#include <queue>
#include "CentipedeDirectionState.h"
#include "CentiBodyDirection.h"
using std::queue;

class CentipedeHead;
class Bullet;
enum class CentiMovementDirectionEnum;

class CentipedeBody : public GameObject, public CentipedePart
{
public:
	CentipedeBody();
	void InitializeBody(sf::Vector2f const& pos, CentiMovementDirectionEnum direction);

	virtual ~CentipedeBody() = default;
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;
	
	void UpdateBody(const float & x, const float & y);
	void AddOffset(sf::Vector2f const &offset, CentiMovementDirectionEnum direction);
	sf::Vector2f GetPosition();

	virtual void Collision(GameObject *g) override {};
	virtual void Collision(Bullet * bullet);

	void RemoveBodyFromScreen(); ///this will handle sprite, active, and recycling

private:
	virtual void Draw() override;
	virtual void Update() override;
	
	void ChangePos();
	CentiBodyDirection *GetDirectionState(CentiMovementDirectionEnum e);

	const CentiBodyDirection *bodyDirection;

	CentiMovementDirectionEnum currentDirection;
	AheadInformation aheadTurningInformation;
	std::queue<AheadInformation> offsetQueue;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	sf::Vector2f currentOffset;

	bool active;
	unsigned int animationCounter;
};


#endif //CENTIPEDEBODY_H