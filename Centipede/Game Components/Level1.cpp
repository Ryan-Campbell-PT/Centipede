// CentipedeLevel
// Andre Berthiaume, MArch 2013

#include "TEAL\CommonElements.h"

#include "Level1.h"
#include "Ship.h"
#include "Bullet.h"
#include "HUD.h"
#include "Mushroom.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "CentipedeHead.h"

#include <vector>

//commented out for now to have reference to code for later
/*
void Level1::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,64,255) );

	new WidgetGenerator;
	new AsteroidField;
	new Ship;
	new HUD;

	CollisionTestPair<Bullet,Asteroid>();
	CollisionTestPair<Ship,Widget>();
	CollisionTestPair<Ship,Asteroid>();

};
*/

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	Ship::GetInstance(); //spawn the ship



	MushroomFactory::GetInstance(50);
	new CentipedeHead(sf::Vector2f(500, 30));
	

	CollisionTestPair<Ship, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();

}

