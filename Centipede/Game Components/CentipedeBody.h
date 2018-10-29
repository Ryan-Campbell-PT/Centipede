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
	void InitializeBody(sf::Vector2f const& pos, OffsetArray direction);

	virtual ~CentipedeBody();
	CentipedeBody &operator=(const CentipedeBody &c) = delete;
	CentipedeBody(const CentipedeBody &c) = delete;
	
	void UpdateBody(const float & x, const float & y);
	void AddOffset(sf::Vector2f const &offset, CentiMovementDirectionEnum direction);
	sf::Vector2f GetPosition();

	virtual void Collision(GameObject *g) override {};
	virtual void Collision(Bullet * bullet);

	//void SendDataBack();
	void GetDataFromFront(OffsetArray offset);

private:
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Destroy() override;
	
	void ChangePos();
	///this method will convert head directions into the simplified states the body's use
	const CentiBodyDirection *GetDirectionState(CentiMovementDirectionEnum e);

	AheadInformation aheadTurningInformation;
	std::queue<AheadInformation> offsetQueue;

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	sf::Vector2f currentOffset;

	unsigned int animationCounter;

	ScoreCmd *pDeath;

	OffsetArray currentOffsetArray;
	OffsetArray pastOffsetArray;
};


#endif //CENTIPEDEBODY_H