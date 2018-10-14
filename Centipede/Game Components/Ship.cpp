// Ship
// Andre Berthiaume, Aug 2012

#include "Ship.h"
#include "Bullet.h"
#include "GameController.h"
#include "ShipExplosion.h"
#include "Widget.h"
#include "Asteroid.h"
#include "BulletFactory.h"
#include "Mushroom.h"
#include "ScorpionManager.h"
#include "SpiderManager.h"
#include "KeyboardIncludes.h"

Ship *Ship::instance = 0;

Ship::Ship()
{
	bitmap = ResourceManager::GetTextureBitmap("PlayerShip"); 
	this->sprite = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));

	this->sprite.setOrigin( sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setPosition(position);
	
	this->position = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f, WindowManager::MainWindow.getView().getSize().y * .9f);
	
	this->GunOffset = sf::Vector2f(0, 0);
		
	SetCollider(sprite, bitmap, true);
	RegisterCollision<Ship>(*this);

	FireSnd.setBuffer( ResourceManager::GetSound("Fire1")  );
	FireSnd.setPitch(2);
	FireSnd.setVolume(25);
	
	SetDrawOrder(1000);

	SetKeyboardCommands();
	RegisterInput( InputFlags::KeyPressed ); // Recieve single-presses events
}

void Ship::SetKeyboardCommands()
{
	this->keyDown = new	Ship_Right(sf::Keyboard::S);
	this->keyUp = new Ship_Left(sf::Keyboard::W);
	this->keyRight = new Ship_Right(sf::Keyboard::D);
	this->keyLeft = new Ship_Left(sf::Keyboard::A);
	this->keyFire = new Ship_Fire(sf::Keyboard::Space);
}

Ship * Ship::GetInstance()
{
	if (instance == 0)
		instance = new Ship;

	return instance;
}

void Ship::Destroy()
{
	DeregisterInput();
	DeregisterCollision<Ship>(*this);
}

void Ship::InitalizeShip()
{
	GetInstance();
}

void Ship::Update()
{
	if (sf::Keyboard::isKeyPressed(this->keyLeft->GetCommand())) position.x -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyUp->GetCommand())) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyDown->GetCommand())) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyRight->GetCommand())) position.x += this->SPEED;
	// Continuous key-down tests
	
	//may not want this in update sequence, one extra if that isnt necessary
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::AttemptSpawnBullet(position + GunOffset))
		{
		}//FireSnd.play(); //only play the sound if the bullet can be spawned
	}

	Tools::Clamp<float>(
		position.x,
		this->sprite.getTextureRect().width / 2.f,
		WindowManager::MainWindow.getView().getSize().x - (this->sprite.getTextureRect().width / 2.f)
		);
#if !TESTING //for testing purposes
	Tools::Clamp<float>(
		position.y,
		WindowManager::MainWindow.getView().getSize().y - (this->sprite.getTextureRect().height * SHIP_BOUNDS),
		WindowManager::MainWindow.getView().getSize().y - (this->sprite.getTextureRect().height / 2.f)
		);
#endif
	sprite.setPosition(position);
}

void Ship::Collision(Widget *other)
{
	GameController::Instance().AddScore( other->GetValue() );
	other->MarkForDestroy();
}

void Ship::Collision(Mushroom* other)
{
	if (sf::Keyboard::isKeyPressed(this->keyLeft->GetCommand())) position.x += this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyUp->GetCommand())) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyDown->GetCommand())) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(this->keyRight->GetCommand())) position.x -= this->SPEED;

	sprite.setPosition(position);
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	//todo: this will have to be changed in the future, for now will keep
	if (k == sf::Keyboard::Key::C)
		ScorpionManager::SpawnScorpion();

	if (k == sf::Keyboard::Key::X)
		SpiderManager::SpawnSpider();
}

sf::Vector2f Ship::GetPosition()
{
	return GetInstance()->position;
}

void Ship::SetState(const ShipMode * state)
{
	GetInstance()->shipMode = state;
}

void Ship::DestroyShip()
{
	ConsoleMsg::WriteLine("BOOM");
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(sprite);
}

