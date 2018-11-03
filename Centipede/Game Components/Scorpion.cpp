#include "Scorpion.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "GameGrid.h"
#include "Ship.h"
#include "ScorpionManager.h"
#include "ScoreManager.h"

Scorpion::Scorpion()
{
	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);
	this->sprite.SetAnimation(0, 3);
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	//this->sprite.setScale(0.f, 0.f);

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);
	this->spawnSound = SoundManager::GetSound(SoundManager::SoundEvent::FleaSpawn);

	SetCollider(sprite, bitmap, true);
}

Scorpion::~Scorpion()
{
	delete pDeath;
}

void Scorpion::Update()
{
	if (++counter % SPRITE_REFRESH == 0)
		this->sprite.NextFrame();

	if (spawnOnLeft)
	{
		this->position.x += Game::FrameTime() * SPEED;

		if (this->position.x > WindowManager::MainWindow.getSize().x)
		{
			this->MarkForDestroy();
			ScorpionManager::SetTimer();
		}
	}

	else
	{
		this->position.x -= Game::FrameTime() * SPEED;

		if (this->position.x < 0)
		{
			this->MarkForDestroy();
			ScorpionManager::SetTimer();
		}
	}

	this->sprite.setPosition(this->position);
}

void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Scorpion::SpawnScorpion(sf::Vector2f & pos)
{
	this->position = pos;
	this->sprite.setPosition(pos);

	this->spawnOnLeft = pos.x < SPRITE_SIZE;
	//this->sprite.setScale(1.f, 1.f);
	SoundManager::SendSoundCommand(this->spawnSound);

	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Collision(Bullet * bullet)
{
	bullet->MarkForDestroy();
	ScoreManager::SendScoreCmd(this->pDeath);
	//ScorpionManager::RemoveScorpion(this); //let the manager handle recyling
	ScorpionManager::SetTimer(); //because it was destroyed by the bullet, we can spawn again
	this->MarkForDestroy(); //remove from screen/teal
}

void Scorpion::Collision(Mushroom * shroom)
{
	if (shroom->GetState() == MushroomState::Healthy)
		shroom->SetState(MushroomState::Poison);
}

void Scorpion::Collision(Ship * ship)
{
	ship->DestroyShip();
}

void Scorpion::Destroy()
{
	//i dont want to handle setting the timer in the destroy method, because 
	//not every time the scorp is destroyed (like end of level) do we want it spawning again
	this->DeregisterCollision<Scorpion>(*this);
}

void Scorpion::SetSpawnSide(bool b)
{
	spawnOnLeft = b;
}

/*void Scorpion::RemoveScorpion()
{
	this->active = false;
	this->sprite.setScale(0.f, 0.f);

}
*/