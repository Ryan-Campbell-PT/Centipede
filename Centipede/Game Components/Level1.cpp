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

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include <fstream>
#include "Level2.h"

Level1::Level1()
	:currentLevelNum(1)
{
	MushroomManager::InitializeMushroomField(15);
}

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
	
	//TextEditor::CurrentScore(368);

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
	//_CrtDumpMemoryLeaks();  
}
