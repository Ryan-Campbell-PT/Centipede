// CentipedeLevel
// Andre Berthiaume, MArch 2013

#include "TEAL\CommonElements.h"

#include "Level1.h"
#include "Ship.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "CentipedeHead.h"
#include "FleaManager.h"
#include "Flea.h"
#include "Scorpion.h"
#include "ScorpionFactory.h"
#include "Spider.h"
#include "SpiderManager.h"
#include "MushroomManager.h"
#include "CentiHeadManager.h"
#include "CentipedeBody.h"

#include <vector>
#include "ScorpionManager.h"
#include "WaveManager.h"


struct Ding : public GameObject
{
	virtual void Update() override
	{
		this->sprite.setPosition(200, 400);
	}

	virtual void Draw() override
	{
		this->sprite = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));
		WindowManager::MainWindow.draw(this->sprite);
	}

	void Alarm0() override
	{
		this->RegisterToCurrentScene();
	}

	void Thing()
	{
		this->sprite.setPosition(200, 400);
	}
	
	
	int far = 16;
	sf::Sprite sprite;
};

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black
/*
	Ship::InitalizeShip(); //spawn the ship


	FleaManager::InitializeFlea(25);
	ScorpionManager::InitializeScorpion(5.f);
	SpiderManager::InitializeSpider(2);
	CentiHeadManager::InitializeCentipede(1, 1.5f, 0, 0);
*/
/*	auto d = new Ding;
	d->far = 8;
	d->MarkForDestroy();
	d->far = 16;
	//d->Draw();
	//d->SetAlarm(0, 1);
	d->RegisterToCurrentScene();
	d->Thing();
	*/
	WaveManager::SetupLevel(1);
	MushroomManager::InitializeMushroomField(15);

	CollisionTestPair<Ship, Mushroom>();

	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Bullet, Spider>();

	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Scorpion, Ship>();

	CollisionTestPair<Spider, Mushroom>();
	CollisionTestPair<Spider, Ship>();

	CollisionTestPair<Flea, Ship>();

	CollisionTestPair<CentipedeBody, Bullet>();
	CollisionTestPair<CentipedeHead, Bullet>();
}
