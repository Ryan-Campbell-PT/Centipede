#include "LevelAttractor.h"
#include "PlayerManager.h"
#include "MushroomManager.h"
#include "Mushroom.h"
#include "Bullet.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Ship.h"
#include "Flea.h"
#include "Spider.h"
#include "Scorpion.h"
#include "TextEditor.h"

void LevelAttractor::Initialize()
{
	//todo:
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black
	
	PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
	MushroomManager::InitializeMushroomField(15);
	TextEditor::AttractorMode(true);

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

/*void LevelAttractor::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if(k == sf::Keyboard::Num1)
	{
		PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player1);
	}//one player mode

	else if(k == sf::Keyboard::Num2)
	{
		PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player2);
	}//two player mode
}*/
