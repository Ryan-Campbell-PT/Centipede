// Ship
// Andre Berthiaume, Aug 2012

#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

// Forward declarations
class Widget;
class Asteroid;
class Mushroom;

class Ship : public GameObject
{
public:
	static Ship * GetInstance();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	
	virtual void Collision( GameObject *other ){};
	virtual void Collision(Widget *other);
	virtual void Collision(Mushroom* other);

private:
	Ship(); //singleton instance

	static Ship *instance;

	float SPEED;
	float HBORDER;
	float TBORDER;
	sf::Vector2f GunOffset;

	float offset;

	sf::Vector2f Pos;
	sf::Vector2f Impulse;
	float friction;

	sf::Sprite MainSprite; //changed from AnimatedSprite
	CollisionTools::TextureBitmap bitmap;

	sf::Sound FireSnd;
};

#endif _Ship