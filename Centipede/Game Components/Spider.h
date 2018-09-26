#ifndef SPIDER_H
#define SPIDER_H

#include "TEAL/CommonElements.h"

#define RANDOM_CHANGE_NUM 100
#define Y_BOUNDS 50

class Bullet;
class Mushroom;
class Ship;
enum class SpiderDirection;

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
	
	void SpawnSpider(sf::Vector2f pos);

private:
	void RemoveSpider();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	bool active;
	int SPEED = 100;
	int boundsTopY, boundsBottomY;
	int counterNum;
	int verticalRandomNum;

	//these two variabels will change in the future, will keep for simplicity for now
	SpiderDirection leftOrRight;
	SpiderDirection upOrDown;
	SpiderDirection prevLeftOrRight;

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

