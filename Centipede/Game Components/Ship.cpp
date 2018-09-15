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
	this->SPEED = 7;
	this->HBORDER = 15;
	this->TBORDER = 600;
	
	//bitmap = ResourceManager::GetTextureBitmap("PlayerShip"); 
	this->MainSprite = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));
	//MainSprite.SetAnimation(0,3, false, false); 

	this->MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	this->MainSprite.setScale(2,2);
	this->MainSprite.setPosition(Pos);
	
	this->Pos = sf::Vector2f(WindowManager::MainWindow.getView().getSize().y / 1.5f, WindowManager::MainWindow.getView().getSize().x / 1.5f);
	this->Impulse = sf::Vector2f(0,0);
	this->friction = .97f;
	
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
	
	//MainSprite.Update(); //not sure if this is needed
	
	offset = SPEED * Game::FrameTime();
	// Continuous key-down tests
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A)) Impulse += sf::Vector2f(-offset, 0);
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D)) Impulse += sf::Vector2f( offset, 0);
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W)) Impulse += sf::Vector2f(0, -offset);
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S)) Impulse += sf::Vector2f(0, offset);
	
	//may not want this in update sequence, one extra if that isnt necessary
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//ConsoleMsg::WriteLine("Pew! Pew!");

		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::GetInstance()->SpawnBullet(Pos + GunOffset))
			FireSnd.play(); //only play the sound if the bullet can be spawned
	}

	Pos += Impulse;
	Tools::Clamp<float>(Pos.x, (float) 2*MainSprite.getTextureRect().width, WindowManager::MainWindow.getView().getSize().x );
	Tools::Clamp<float>(Pos.y, 100, WindowManager::MainWindow.getView().getSize().y - MainSprite.getTextureRect().height);	
	MainSprite.setPosition(Pos);

	Impulse *= friction;
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
/*	if (k == sf::Keyboard::Space)
	{
		//ConsoleMsg::WriteLine("Pew! Pew!");

		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::GetInstance()->SpawnBullet(Pos + GunOffset))
			FireSnd.play(); //only play the sound if the bullet can be spawned
	}
*/
}

void Ship::Collision(Widget *other)
{
	GameController::Instance().AddScore( other->GetValue() );
	other->MarkForDestroy();
}

void Ship::Collision(Mushroom* other)
{
	//other->Explode();
	//new ShipExplosion(Pos);
	//MarkForDestroy();
	ConsoleMsg::WriteLine("Ship[");
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

