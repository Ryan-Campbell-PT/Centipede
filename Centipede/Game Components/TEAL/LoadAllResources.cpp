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

	AddTexture("Blaster", "blaster.png");
	AddTexture("Bullet", "bullet.png");
	AddTexture("CentipedeBody", "centipede_body.png");
	AddTexture("CentipedeHead", "centipede_head.png");
	AddTexture("Death", "death.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Spawn", "spawn.png");
	AddTexture("Spider", "spider.png");

	AddSound("Fire1", "fire1.wav");

	//AddTexture("Spaceship", "SpaceShip2.png");
	//AddTexture("Shots", "ColoredShots.png");
	//AddTexture("Mine", "Mine.png");
	//AddTexture("Asteroids", "asteroids.png");
	//AddTexture("Explosion", "Explosion.png");

	//AddTexture("Splashpage", "DemoSplash.jpg", false);

	//AddSound("Boom", "bazooka3.wav");
	//AddSound("Zap", "scifiblast.wav");
	//AddSound("Ding", "glass.wav");

	//AddFont("PointFont", "MotorwerkOblique.ttf");
}

