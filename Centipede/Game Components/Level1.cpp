// CentipedeLevel
// Andre Berthiaume, MArch 2013

#include "TEAL\CommonElements.h"

#include "Level1.h"
#include "Ship.h"
#include "AsteroidField.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "WidgetGenerator.h"
#include "Widget.h"
#include "HUD.h"
#include "FinalScore.h"
#include "Mushroom.h"
#include "MushroomFactory.h"

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

	/*std::vector<Mushroom*> d;
	
	d.push_back(new Mushroom(sf::Vector2f(300, 400)));
	d.push_back(new Mushroom(sf::Vector2f(15 * 24, 36)));
	d.push_back(new Mushroom(sf::Vector2f(15 * 24, 12)));
	d.push_back(new Mushroom(sf::Vector2f(0 * 24, 12)));
	
	auto front = d.front();
	auto back = d.back();
	d.pop_back();*/

	MushroomFactory::GetInstance(100);

	CollisionTestPair<Ship, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();

}