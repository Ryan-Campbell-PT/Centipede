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
	
	virtual void Collision( GameObject *other ){};
	virtual void Collision(Widget *other);
	virtual void Collision(Mushroom* other);
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

	sf::Vector2f GetPosition();

//private:
	Ship(); //singleton instance

	static Ship *instance;

	const float SPEED = 3;
	sf::Vector2f GunOffset;

	sf::Vector2f Pos;
	
	sf::Sprite MainSprite; //changed from AnimatedSprite
	CollisionTools::TextureBitmap bitmap;

	sf::Sound FireSnd;
};

#endif _Ship