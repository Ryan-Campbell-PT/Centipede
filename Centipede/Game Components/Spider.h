#ifndef SPIDER_H
#define SPIDER_H

#include "TEAL/CommonElements.h"
#include "ScoreCmd.h"

#define RANDOM_CHANGE_NUM 100
#define Y_BOUNDS 50
#define SPIDER_CHANGE false

class Bullet;
class Mushroom;
class Ship;
enum class SpiderDirection;
class ScoreCmd;
class ImprovedSpiderState;

class Spider : public GameObject
{
public:
	Spider();
	virtual ~Spider();
	Spider &operator=(const Spider &c) = delete;
	Spider(const Spider &c) = delete;

	virtual void Update() override;
	virtual void Draw() override;

	virtual void Collision(GameObject *) {};
	virtual void Collision(Bullet * bullet);
	virtual void Collision(Mushroom * shroom);
	virtual void Collision(Ship *ship);
	
	void SpawnSpider(sf::Vector2f pos, const float spiderSpeed);

private:
	void RemoveSpider();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	bool active;
	float SPEED = 1.5f;
	int boundsTopY, boundsBottomY;
	int counterNum;

	const ImprovedSpiderState *spiderState = nullptr;

	ScoreCmd* pDeath;
};
enum class SpiderDirection
{
	Left,
	Right,
	Up,
	Down,
	Vertical
};

#endif //SPIDER_H

