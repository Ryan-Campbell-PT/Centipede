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
#include "ScorpionFactory.h"
#include "SpiderFactory.h"

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

void Ship::InitalizeShip()
{
	GetInstance();
}

void Ship::Update()
{
	//offset = SPEED * Game::FrameTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) position.x -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) position.x += this->SPEED;
	// Continuous key-down tests
	
	//may not want this in update sequence, one extra if that isnt necessary
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::AttemptSpawnBullet(position + GunOffset))
			FireSnd.play(); //only play the sound if the bullet can be spawned
	}

	Tools::Clamp<float>(
		position.x,
		this->sprite.getTextureRect().width / 2.f,
		WindowManager::MainWindow.getView().getSize().x - (this->sprite.getTextureRect().width / 2.f)
		);
#if TESTING //for testing purposes
	Tools::Clamp<float>(
		position.y,
		WindowManager::MainWindow.getView().getSize().y - (this->sprite.getTextureRect().height * 7.f),
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) position.x += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) position.x -= this->SPEED;

	sprite.setPosition(position);
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	//todo: this will have to be changed in the future, for now will keep
	if (k == sf::Keyboard::Key::C)
		ScorpionFactory::SpawnScorpion();

	if (k == sf::Keyboard::Key::X)
		SpiderFactory::SpawnSpider();
}

sf::Vector2f Ship::GetPosition()
{
	return GetInstance()->position;
}
//	static Ship * GetInstance();

void Ship::DestroyShip()
{
	ConsoleMsg::WriteLine("BOOM");
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(sprite);
}

