#ifndef SPIDER_H
#define SPIDER_H

#include "TEAL/CommonElements.h"

class Spider : public GameObject
{
public:
	Spider();
	virtual ~Spider();
	Spider &operator=(const Spider &c) = delete;
	Spider(const Spider &c) = delete;

	virtual void Update() override;
	virtual void Draw() override;

private:
	sf::Vector2f position;
	AnimatedSprite sprite;
	CollisionTools::TextureBitmap bitmap;

};

#endif //SPIDER_H

