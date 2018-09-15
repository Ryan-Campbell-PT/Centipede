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


	//CollisionTestPair<Ship, Mushroom>();
}