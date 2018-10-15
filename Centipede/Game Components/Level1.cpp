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

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	Ship::InitalizeShip(); //spawn the ship

	MushroomManager::InitializeMushroomField(30);

	FleaManager::InitializeFlea(25);
	ScorpionManager::InitializeScorpion(5.f);
	CentiHeadManager::InitializeCentipede(6, 1.5f, 0, 0);

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
