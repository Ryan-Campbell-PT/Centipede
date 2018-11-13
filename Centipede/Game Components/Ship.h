// Ship
// Andre Berthiaume, Aug 2012

#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

#define SHIP_BOUNDS 7.f

// Forward declarations
class Flea;
class Scorpion;
class Spider;
class CentipedeBody;
class CentipedeHead;
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
	enum class ShipModeEnum
	{
		Attractor, Player
	};

	static sf::Vector2f GetPosition();
	static void SetState(ShipMode *state);

	virtual void Collision(GameObject *) override {}
	virtual void Collision(Mushroom*);
	virtual void Collision(Spider *);
	virtual void Collision(Scorpion *);
	virtual void Collision(Flea *);
	virtual void Collision(CentipedeBody *);
	virtual void Collision(CentipedeHead *);
	static void Terminate(GameObject *);

	static void InitializeShip(ShipModeEnum state);
	///the purpose for using ReinitializeShip instead of MarkForDestroy is because when swapping
	///scenes, it results in problems for destroyed GO, so i instaed just reinitialize it, or have the
	///PlayerManager handle the destruction
	static void ReinitializeShip();
	
	static void RemoveInput();;

private:
	Ship(); //singleton instance
	virtual ~Ship() = default;
	static Ship * GetInstance();
	void SetKeyboardCommands() const;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey) override;

	void reinitializeShip();

	static Ship *instance;

	const float SPEED = 2.5f;
	sf::Vector2f position;
	sf::Sprite sprite;
	CollisionTools::TextureBitmap bitmap;

	SoundCmd *fireSound;
	float timeToSpawn;
	PlayerInput *playerInput;
	ShipMode *shipMode;

	ShipMode * mode_player, *mode_attractor;
};

#endif _Ship