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
#include "TextEditor.h"

#include <iostream>
#include <fstream>
#include "Level2.h"
#include "PlayerManager.h"
#include "CentiHeadPool.h"
#include "BulletManager.h"

//Level1::Level1()
//	:currentLevelNum(1)
//{
//	//MushroomManager::InitializeMushroomField(15);
//}

void Level1::Initialize()
{	
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	//PlayerManager::SetPlayerMode(PlayerData::PlayerID::Player1);
	WaveManager::SetupLevel(1);
	MushroomManager::InitializeMushroomField(15);
	
	PlayerManager::InitializePlayer(PlayerData::PlayerID::Player1 ); //todo fix
	
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
	CollisionTestPair<CentipedeHead, Ship>();
	CollisionTestPair<CentipedeBody, Ship>();
}

void Level1::Terminate()
{	
	CentiHeadManager::Terminate();
	CentiBodyManager::Terminate();
	FleaManager::Terminate();
	MushroomManager::Terminate();
	BulletManager::Terminate();
}
