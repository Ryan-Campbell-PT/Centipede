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
#include "GameGrid.h"

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

#if false
	std::vector<Mushroom*> d;

	d.push_back(new Mushroom(sf::Vector2f(0, 0)));
	d.push_back(new Mushroom(sf::Vector2f(0, 330)));
	d.push_back(new Mushroom(sf::Vector2f(330, 0)));
	d.push_back(new Mushroom(sf::Vector2f(450, 450)));

	auto front = d.front();
	auto back = d.back();
	d.pop_back();

#elif true

	MushroomFactory::GetInstance(100);

#elif true
	for (int i = 0; i < 30; i++)
	{
		auto f = rand() % 30;
		new Mushroom(sf::Vector2f(f * 24, f * 24));
	}

#elif true
	//auto f = (sf::Vector2f(66, 31));
	//MushroomFactory::GetInstance()->GetNewMushroomPosition(f);
	new Mushroom(66, 31);
	new Mushroom(73, 31);
	
#endif

	CollisionTestPair<Ship, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();

}

