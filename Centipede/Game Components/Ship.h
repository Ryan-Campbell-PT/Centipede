// Ship
// Andre Berthiaume, Aug 2012

#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

// Forward declarations
class Widget;
class Asteroid;
class Mushroom;
class KeyboardCommand;

class Ship : public GameObject
{
public:
	static void InitalizeShip();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	
	virtual void Collision( GameObject *other ){};
	virtual void Collision(Widget *other);
	virtual void Collision(Mushroom* other);
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

	static sf::Vector2f GetPosition();

	///not static because you shouldnt just be able to always destroy the ship, you need the ship itself
	void DestroyShip(); 

private:
	Ship(); //singleton instance
	void SetKeyboardCommands();

	static Ship *instance;

	const float SPEED = 3;
	sf::Vector2f GunOffset;
	sf::Vector2f position;
	sf::Sprite sprite; //changed from AnimatedSprite
	CollisionTools::TextureBitmap bitmap;

	sf::Sound FireSnd;
	
	static Ship * GetInstance();

	KeyboardCommand *keyDown, *keyUp, *keyRight, *keyLeft, *keyFire;
};

#endif _Ship