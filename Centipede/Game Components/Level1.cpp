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

#include <vector>

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	Ship::InitalizeShip(); //spawn the ship

	auto a = 0 % 3;
	auto f = 1 % 3;
	auto g = 2 % 3;
	auto r = 3 % 3;
	auto t = 4 % 3;



	MushroomManager::InitializeMushroomField(30);
	//auto shroom = new Mushroom();
//	shroom->InitializeMushroom(sf::Vector2f(200, 200));
	FleaManager::InitializeFlea();
	
	
	new CentipedeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2, 0), 3);

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
}

