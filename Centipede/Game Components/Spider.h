#ifndef SPIDER_H
#define SPIDER_H

#include "TEAL/CommonElements.h"

#define RANDOM_CHANGE_NUM 300

class Bullet;
class Mushroom;
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

	void SpawnSpider(sf::Vector2f pos);

	void Collision(GameObject *) {};
	void Collision(Bullet * );
	void Collision(Mushroom *);

private:
	void RemoveSpider();

	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

	bool active;
	int SPEED = 100;

	int randomNum;

	//these two variabels will change in the future, will keep for simplicity for now
	SpiderDirection leftOrRight;
	SpiderDirection upOrDown;


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

