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

	virtual void Collision(GameObject *) override{};
	virtual void Collision(Bullet *);
	virtual void Collision(Mushroom *);
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;

	void SpawnSpider(sf::Vector2f pos, const float spiderSpeed);

private:
	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	float SPEED = 1.5f;
	int boundsTopY, boundsBottomY;
	int counterNum;

	const ImprovedSpiderState *spiderState = nullptr;

	ScoreCmd* pDeath;
	SoundCmd *spawnSound;
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

