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

Ship *Ship::instance = 0;

Ship::Ship()
{
	bitmap = ResourceManager::GetTextureBitmap("PlayerShip"); 
	this->MainSprite = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));

	this->MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	this->MainSprite.setPosition(Pos);
	
	this->Pos = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f, WindowManager::MainWindow.getView().getSize().y * .9f);
	
	this->GunOffset = sf::Vector2f(0, 0);
		
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Ship>(*this);

	FireSnd.setBuffer( ResourceManager::GetSound("Fire1")  );
	FireSnd.setPitch(2);
	FireSnd.setVolume(25);
	
	SetDrawOrder(1000);

	RegisterInput( InputFlags::KeyPressed ); // Recieve single-presses events
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

void Ship::Update()
{
	//offset = SPEED * Game::FrameTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Pos.x -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Pos.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Pos.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Pos.x += this->SPEED;
	// Continuous key-down tests
	
	//may not want this in update sequence, one extra if that isnt necessary
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::GetInstance()->SpawnBullet(Pos + GunOffset))
			FireSnd.play(); //only play the sound if the bullet can be spawned
	}

	Tools::Clamp<float>(
		Pos.x,
		this->MainSprite.getTextureRect().width / 2.f,
		WindowManager::MainWindow.getView().getSize().x - (this->MainSprite.getTextureRect().width / 2.f)
		);
#if false //for testing purposes
	Tools::Clamp<float>(
		Pos.y,
		WindowManager::MainWindow.getView().getSize().y - (this->MainSprite.getTextureRect().height * 7.f),
		WindowManager::MainWindow.getView().getSize().y - (this->MainSprite.getTextureRect().height / 2.f)
		);
#endif
	MainSprite.setPosition(Pos);
}

void Ship::Collision(Widget *other)
{
	GameController::Instance().AddScore( other->GetValue() );
	other->MarkForDestroy();
}

void Ship::Collision(Mushroom* other)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Pos.x += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Pos.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Pos.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Pos.x -= this->SPEED;

	MainSprite.setPosition(Pos);
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
}

sf::Vector2f Ship::GetPosition()
{
	return this->Pos;
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

