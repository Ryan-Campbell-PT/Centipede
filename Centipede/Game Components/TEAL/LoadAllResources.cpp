// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../Splash.h"
//#include "../../reference/Asset/Sounds/"
//#include "../../reference/Asset/Sprites/"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new Splash() );

	AddTexture("PlayerShip", "blaster.png");
	AddTexture("Bullet", "bullet.png");
	AddTexture("CentiBody", "centipede_body.png");
	AddTexture("CentiHead", "centipede_head.png");
	AddTexture("CentiSegment", "centipede_segment.png");
	AddTexture("Death", "death.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Spawn", "spawn.png");
	AddTexture("Spider", "spider.png");

	AddSound("Fire1", "fire1.wav");

	AddFont("PointFont", "MotorwerkOblique.ttf"); //keep this for now since we have no other fonts
	
	//AddTexture("Splashpage", "DemoSplash.jpg", false);

}

