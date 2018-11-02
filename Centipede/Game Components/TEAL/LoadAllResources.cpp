// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../Splash.h"

#include "../Ship.h"

#include "../WaveManager.h"
#include "../LevelAttractor.h"
#include "../Level1.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new LevelAttractor );
	
	AddTexture("PlayerShip", "blaster.png");
	AddTexture("Bullet", "bullet.png");
	AddTexture("CentiBody", "centipede_segment.png");
	AddTexture("CentiHead", "centipede_head.png");
	AddTexture("CentiSegment", "centipede_segment.png");
	AddTexture("Death", "death.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Spawn", "spawn.png");
	AddTexture("Spider", "spider.png");

	AddSound("Fire1", "fire1.wav");
	AddSound("Flea", "flea_new.wav");
	AddSound("Spider", "spider_new.wav");
	AddSound("Death", "death.wav");
	AddSound("Scorpion", "scorpion_new.wav");
	AddSound("Beat", "beat.wav");

	AddFont("PointFont", "MotorwerkOblique.ttf" );

	AddTexture("Alphabet", "FONT.bmp");
	AddTexture("Keys", "Keycaps.tga");
	
	WaveManager::LoadLevelInfo("WaveData.txt");


}

