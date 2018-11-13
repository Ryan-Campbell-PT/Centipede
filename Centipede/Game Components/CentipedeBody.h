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
class ScoreCmd;

class CentipedeBody : public GameObject, public CentipedePart
{
public:
	CentipedeBody();
	void InitializeBody(sf::Vector2f const& pos, const int &speed, OffsetArray direction);

	virtual ~CentipedeBody();
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;

	sf::Vector2f GetPosition() const;

	virtual void Collision(GameObject *) override {}
	virtual void Collision(Bullet *);

	void GetDataFromFront(OffsetArray offset);

private:
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Destroy() override;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	unsigned int animationCounter;
	int speed;

	ScoreCmd *pDeath;

	OffsetArray currentOffsetArray;
};


#endif //CENTIPEDEBODY_H