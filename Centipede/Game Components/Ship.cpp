// Ship
// Andre Berthiaume, Aug 2012

#include "Ship.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Mushroom.h"
#include "CentipedeHead.h"
#include "PlayerManager.h"
#include "PlayerInput.h"
#include "ShipMode.h"
#include "SoundCmd.h"
#include "GameManager.h"
#include "ExplosionManager.h"

Ship *Ship::instance = nullptr;

Ship::Ship()
	:timeToSpawn(3.f), shipMode(nullptr)
{
	bitmap = ResourceManager::GetTextureBitmap("PlayerShip");
	this->sprite = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setPosition(position);
	SetCollider(sprite, bitmap, true);

	playerInput = new PlayerInput;
	PlayerManager::SetPlayerControls(this->playerInput);
	RegisterInput(InputFlags::KeyPressed); // Recieve single-presses events

	this->fireSound = SoundManager::GetSound(SoundManager::SoundEvent::ShipFire);
}

Ship * Ship::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Ship;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void Ship::Destroy()
{
	DeregisterInput();
	DeregisterCollision<Ship>(*this);
}

void Ship::Alarm0()
{
	this->InitializeShip(this->shipMode);
}

void Ship::Update()
{
	this->shipMode->MoveShip(this->playerInput, this->position, this->SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		if (BulletManager::AttemptSpawnBullet())
			SoundManager::SendSoundCommand(this->fireSound); //only play the sound if the bullet can be spawned

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

void Ship::Collision(Mushroom*)
{
	//let the state handle what happens when I collide
	this->shipMode->MushroomCollision(this->playerInput, this->position, this->SPEED);

	sprite.setPosition(position);
}

void Ship::Collision(Spider *)
{
	ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::PlayerDeath, this->position);
	this->reinitializeShip();
	PlayerManager::PlayerDeath();
}

void Ship::Collision(Scorpion *)
{
	ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::PlayerDeath, this->position);
	this->reinitializeShip();
	PlayerManager::PlayerDeath();
}

void Ship::Collision(Flea *)
{
	ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::PlayerDeath, this->position);
	this->reinitializeShip();
	PlayerManager::PlayerDeath();
}

void Ship::Collision(CentipedeBody*)
{
	ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::PlayerDeath, this->position);
	this->reinitializeShip();
	PlayerManager::PlayerDeath();
}

void Ship::Collision(CentipedeHead *)
{
	ExplosionManager::DisplayExplosion(ExplosionManager::ExplosionType::PlayerDeath, this->position);
	this->reinitializeShip();
	PlayerManager::PlayerDeath();
}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::Num1) //just for testing purposes
		GameManager::SetPlayerMode(PlayerData::PlayerID::Player1);
	else if (k == sf::Keyboard::Num2)
		GameManager::SetPlayerMode(PlayerData::PlayerID::Player2);
}

void Ship::reinitializeShip()
{
	//always spawn in the center
	GetInstance()->position = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f,
		WindowManager::MainWindow.getView().getSize().y * .9f);

	instance->RegisterInput();
	instance->RegisterCollision<Ship>(*instance);
}

sf::Vector2f Ship::GetPosition()
{
	return GetInstance()->position;
}

void Ship::SetState(ShipMode * state)
{
	delete GetInstance()->shipMode;
	instance->shipMode = state;
}

void Ship::Terminate(GameObject *)
{
	delete instance->fireSound;
	delete instance->playerInput;
	delete instance->shipMode;

	instance->fireSound = nullptr;
	instance->playerInput = nullptr;
	instance->shipMode = nullptr;

	delete instance;
	instance = nullptr;
}

void Ship::InitializeShip(ShipMode * state)
{
	delete GetInstance()->shipMode;
	instance->shipMode = state;

	//always spawn in the center
	instance->position = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f,
		WindowManager::MainWindow.getView().getSize().y * .9f);

	instance->RegisterInput();
	instance->RegisterCollision<Ship>(*instance);
}

void Ship::ReinitializeShip()
{
	GetInstance()->position = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.f,
		WindowManager::MainWindow.getView().getSize().y * .9f);

	instance->RegisterInput();
	instance->RegisterCollision<Ship>(*instance);
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(sprite);
}

