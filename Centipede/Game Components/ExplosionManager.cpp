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

	case ExplosionType::CritterDeath:
		GetInstance()->critterDeath(pos);
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
	this->critterDeath_sprite = AnimatedSprite(ResourceManager::GetTexture("Spawn"), 2, 2, 60, 1, 20, true, false);
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
	this->explosions.push_back(this->playerDeath_sprite);
}

void ExplosionManager::critterDeath(sf::Vector2f pos)
{
	this->critterDeath_sprite.setPosition(pos);
	this->critterDeath_sprite.Reset(); //restart the explosion
	this->explosions.push_back(this->critterDeath_sprite);
}

void ExplosionManager::Draw()
{
	if (!this->explosions.empty())
	{	
		for (auto i = this->explosions.begin(); i != this->explosions.end(); ++i )
		{ //need a while because vectors are sensative bitches
			if ((*i).IsLastAnimationFrame())
			{
				this->explosions.erase(i);
				break;
			}
			else
			{
				WindowManager::MainWindow.draw(*i);
				(*i).NextFrame();
			}
			
		}
	}
}
