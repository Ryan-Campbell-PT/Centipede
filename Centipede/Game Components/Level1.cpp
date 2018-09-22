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
#include "FleaFactory.h"

#include <vector>

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	Ship::GetInstance(); //spawn the ship



	MushroomFactory::GetInstance(30);
	//new CentipedeHead(sf::Vector2f(500, 30));
//	auto flea = new Flea();
	FleaFactory::GetInstance();

	CollisionTestPair<Ship, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();

}

