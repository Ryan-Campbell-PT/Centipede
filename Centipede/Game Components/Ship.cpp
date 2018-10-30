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
#include "PlayerManager.h"
#include "PlayerInput.h"
#include "ScoreManager.h"
#include "ShipMode.h"

Ship *Ship::instance = nullptr;

Ship::Ship()
	:shipMode(nullptr)
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

	playerInput = new PlayerInput;
	SetKeyboardCommands();
	RegisterInput( InputFlags::KeyPressed ); // Recieve single-presses events
}

void Ship::SetKeyboardCommands() const
{

	playerInput->keyDown = new	Ship_Right(sf::Keyboard::S);
	playerInput->keyUp = new Ship_Left(sf::Keyboard::W);
	playerInput->keyRight = new Ship_Right(sf::Keyboard::D);
	playerInput->keyLeft = new Ship_Left(sf::Keyboard::A);
	playerInput->keyFire = new Ship_Fire(sf::Keyboard::Space);

	PlayerManager::SetPlayerControls(this->playerInput);
}

Ship * Ship::GetInstance()
{
	if (instance == nullptr)
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
#if false
	if (sf::Keyboard::isKeyPressed(playerInput->keyLeft->GetCommand())) position.x -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyUp->GetCommand())) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyDown->GetCommand())) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyRight->GetCommand())) position.x += this->SPEED;
	// Continuous key-down tests
	
	//may not want this in update sequence, one extra if that isnt necessary
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//the sound could possibly be moved to the SpawnBullet() function to relieve the need for an if
		if (BulletFactory::AttemptSpawnBullet(position + GunOffset))
		{
		}//FireSnd.play(); //only play the sound if the bullet can be spawned
	}

#elif true
	this->shipMode->MoveShip(this->playerInput, this->position, this->SPEED);


#endif

	Tools::Clamp<float>(
		position.x,
		this->sprite.getTextureRect().width / 2.f,
		WindowManager::MainWindow.getView().getSize().x - (this->sprite.getTextureRect().width / 2.f)
		);
#if !TESTING //for testing purposes
	//Tools::Clamp<float>(
	//	position.y,
	//	WindowManager::MainWindow.getView().getSize().y - (this->sprite.getTextureRect().height * SHIP_BOUNDS),
	//	WindowManager::MainWindow.getView().getSize().y - (this->sprite.getTextureRect().height / 2.f)
	//	);
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
	if (sf::Keyboard::isKeyPressed(playerInput->keyLeft->GetCommand())) position.x += this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyUp->GetCommand())) position.y += this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyDown->GetCommand())) position.y -= this->SPEED;
	if (sf::Keyboard::isKeyPressed(playerInput->keyRight->GetCommand())) position.x -= this->SPEED;

	sprite.setPosition(position);
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	//todo: this will have to be changed in the future, for now will keep
	//if (k == sf::Keyboard::Key::C)
		//ScorpionManager::SpawnScorpion();

	//if (k == sf::Keyboard::Key::X)
	//	SpiderManager::SpawnSpider();

	if (k == sf::Keyboard::Key::Z) //just for testing purposes
		if(PlayerManager::GetCurrentPlayer() == PlayerData::PlayerID::Player1)
			PlayerManager::InitializePlayer(PlayerData::PlayerID::Player2);
		
		else
			PlayerManager::InitializePlayer(PlayerData::PlayerID::Player1);

	if (k == sf::Keyboard::Key::T)
	{
		ScoreManager::AddScore(-500); //just for testing purposes
	}
}

sf::Vector2f Ship::GetPosition()
{
	return GetInstance()->position;
}

void Ship::SetState(ShipMode * state)
{
	delete GetInstance()->shipMode;
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

