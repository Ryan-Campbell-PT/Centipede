// Ship
// Andre Berthiaume, Aug 2012

#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

#define SHIP_BOUNDS 7.f

class PlayerInput;
// Forward declarations
class Widget;
class Asteroid;
class Mushroom;
class KeyboardCommand;
class ShipFSM;
class ShipMode;

class Ship : public GameObject
{
public:
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	
	virtual void Collision( GameObject *other ){};
	virtual void Collision(Widget *other);
	virtual void Collision(Mushroom* other);
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

	static sf::Vector2f GetPosition();
	static void SetState(const ShipMode *state);

	///not static because you shouldnt just be able to always destroy the ship, you need the ship itself
	void DestroyShip(); 

private:
	Ship(); //singleton instance
	void SetKeyboardCommands() const;

	static Ship *instance;

	const float SPEED = 2.5f;
	sf::Vector2f GunOffset;
	sf::Vector2f position;
	sf::Sprite sprite; //changed from AnimatedSprite
	CollisionTools::TextureBitmap bitmap;

	sf::Sound FireSnd;
	
	static Ship * GetInstance();

	PlayerInput *playerInput;
	const ShipMode	*shipMode;
};

#endif _Ship