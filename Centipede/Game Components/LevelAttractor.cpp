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
#include "GameManager.h"
#include "WaveManager.h"
#include "CentiBodyManager.h"
#include "CentiHeadManager.h"
#include "FleaManager.h"
#include "BulletManager.h"

void LevelAttractor::Initialize()
{
	//todo:
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255));

	GameManager::SetAttractorMode();
	MushroomManager::InitializeMushroomField(15);
	WaveManager::SetupLevel(0); //allows the designer to determine what is in attractor mode

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
	CollisionTestPair<CentipedeBody, Ship>();
	CollisionTestPair<CentipedeHead, Ship>();

}

void LevelAttractor::Terminate()
{
	CentiHeadManager::Terminate();
	CentiBodyManager::Terminate();
	FleaManager::Terminate();
	MushroomManager::Terminate();
	BulletManager::Terminate();
}
