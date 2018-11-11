#include "ExplosionManager.h"

ExplosionManager * ExplosionManager::instance = nullptr;

void ExplosionManager::DisplayExplosion(ExplosionType type, sf::Vector2f pos)
{
	switch (type)
	{
	case ExplosionType::PlayerDeath:
		GetInstance()->playerDeath(pos);
		break;

	case ExplosionType::SpiderDeath:
		GetInstance()->spiderDeath(pos);
		break;

	default:
		break;
	}
}

void ExplosionManager::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}

ExplosionManager::ExplosionManager()
	:counter(0), playerActive(false)
{
	this->playerDeath_sprite = AnimatedSprite(ResourceManager::GetTexture("Death"), 8, 2, 60, 1, 20, true, false);
}

ExplosionManager * ExplosionManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ExplosionManager;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void ExplosionManager::spiderDeath(sf::Vector2f pos)
{
}

void ExplosionManager::playerDeath(sf::Vector2f pos)
{
	this->playerDeath_sprite.setPosition(pos);
	this->playerActive = true;
}

void ExplosionManager::Draw()
{
	if (this->playerActive)
	{
		if (!this->playerDeath_sprite.IsLastAnimationFrame())
		{
			if (++counter % 2 == 0)  //so the animation doesnt go super fast
			{
				WindowManager::MainWindow.draw(this->playerDeath_sprite);
				this->playerDeath_sprite.NextFrame();
			}
		}

		else
		{
			this->playerDeath_sprite.Reset();
			playerActive = false;
		}
	}



}
