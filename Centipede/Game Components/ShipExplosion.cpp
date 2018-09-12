// ShipExplosion
// Andre Berthiaume, March 2013

#include "ShipExplosion.h"
#include "GameController.h"

ShipExplosion::ShipExplosion( sf::Vector2f pos ) 
{
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Death"), 5, 5, 20); //"Death" may not be the right sprite for the future
	MainSprite.SetAnimation(0, 24); 
	MainSprite.scale(5,5);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(pos);

	//not yet set
	//kaboom.setBuffer( ResourceManager::GetSound("Boom"));
	//kaboom.setPitch(.3f);
	//kaboom.play();
}

void ShipExplosion::Update()
{
	if ( MainSprite.IsLastAnimationFrame() )
	{
		GameController::Instance().PlayerDies();
		MarkForDestroy();
	}

	MainSprite.Update();
}

void ShipExplosion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}