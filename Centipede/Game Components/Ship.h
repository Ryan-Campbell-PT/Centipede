// Ship
// Andre Berthiaume, Aug 2012

#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

#define SHIP_BOUNDS 7.f

class CentipedeBody;
class CentipedeHead;
// Forward declarations
class PlayerInput;
class Widget;
class Asteroid;
class Mushroom;
class KeyboardCommand;
class ShipFSM;
class ShipMode;
class SoundCmd;

class Ship : public GameObject
{
public:

	static sf::Vector2f GetPosition();
	static void SetState(ShipMode *state);

	///not static because you shouldnt just be able to always destroy the ship, you need the ship itself
	//void DestroyShip();

	virtual void Collision(GameObject *other) override {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(CentipedeBody *body);
	virtual void Collision(CentipedeHead *head);
	static void Terminate(GameObject *);

	static void InitializeShip(ShipMode * state);
	
private:
	Ship(); //singleton instance
	virtual ~Ship() = default;
	static Ship * GetInstance();
	void SetKeyboardCommands() const;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual void Alarm0() override;

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey) override;

	static Ship *instance;

	const float SPEED = 2.5f;
	sf::Vector2f position;
	sf::Sprite sprite;
	CollisionTools::TextureBitmap bitmap;

	SoundCmd *fireSound;
	float timeToSpawn;
	PlayerInput *playerInput;
	ShipMode *shipMode;
};

#endif _Ship