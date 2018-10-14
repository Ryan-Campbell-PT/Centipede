#include "Spider.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "Ship.h"
#include "SpiderManager.h"
#include "SpiderStates.h"

#include <random>
#include "ScoreManager.h"
#include "MovementCollection.h"

//TODO: turn gameobjects functions into the Destory() and Initalize() GO objects
Spider::Spider()
{
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.SetAnimation(0, 7);
	this->sprite.setScale(0.f, 0.f);

	SetCollider(sprite, bitmap, true);

	this->active = false;

	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
}

void Spider::Update()
{
	if (!active)
		return;

#if SPIDER_CHANGE

	++counterNum;

	if (counterNum % 20 == 0)
		this->sprite.NextFrame();
	//todo: terrible if statements ahead, im aware, will fix in future
	if (this->counterNum > RANDOM_CHANGE_NUM) //this will add some randomness to the spider
	{
		this->prevLeftOrRight = this->leftOrRight;
		this->leftOrRight = SpiderDirection::Vertical;
		this->verticalRandomNum = rand() % RANDOM_CHANGE_NUM;
		counterNum = 0;
	}
	//if (this->upOrDown == SpiderDirection::Up)
	//	this->upOrDown = SpiderDirection::Down;

	//else
	//	this->upOrDown = SpiderDirection::Up;

//this math is wrong
	if (this->position.y <= this->boundsTopY)
		this->upOrDown = SpiderDirection::Down;
	else if (this->position.y >= this->boundsBottomY)
		this->upOrDown = SpiderDirection::Up;

	if (this->leftOrRight == SpiderDirection::Left)
	{
		this->position.x -= Game::FrameTime() * SPEED;

		if (this->position.x < 0)
			RemoveSpider();
	}

	else if (this->leftOrRight == SpiderDirection::Right)
	{
		this->position.x += Game::FrameTime() * SPEED;

		if (this->position.x > WindowManager::MainWindow.getSize().x)
			RemoveSpider();
	}

	else  //as long as the state is in vertical, we will count the frames its in there and compare to vertRandNum
	{


		if (verticalRandomNum < counterNum)
		{
			this->leftOrRight = this->prevLeftOrRight;
			verticalRandomNum = 0;
			counterNum = 0;
		}
	}

	if (this->upOrDown == SpiderDirection::Up)
		this->position.y -= Game::FrameTime() * SPEED;

	else
		this->position.y += Game::FrameTime() * SPEED;

#elif !SPIDER_CHANGE


	this->position.y += this->spiderState->GetOffsetArray().rowoffset * SPEED;
	this->position.x += this->spiderState->GetOffsetArray().coloffset * SPEED;

	if (this->position.y <= this->boundsTopY)
		this->spiderState = this->spiderState->GetNextState();

	else if (this->position.y >= this->boundsBottomY)
		this->spiderState = this->spiderState->GetNextState();

	#endif

	this->sprite.setPosition(this->position);

}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Spider::SpawnSpider(sf::Vector2f pos)
{


	//#if true
	this->position = pos;
	this->sprite.setPosition(pos);

	this->active = true;
	this->counterNum = rand() % RANDOM_CHANGE_NUM;
	this->boundsTopY = static_cast<int>(pos.y - Y_BOUNDS);
	this->boundsBottomY = static_cast<int>(pos.y + Y_BOUNDS);
	this->verticalRandomNum = rand() % RANDOM_CHANGE_NUM;

#if SPIDER_CHANGE
	if (pos.x == 0) //spawning on left, so we are moving right
		this->leftOrRight = SpiderDirection::Right;
	else
		this->leftOrRight = SpiderDirection::Left;

#elif !SPIDER_CHANGE
	if (pos.x == 0)
		this->spiderState = &Spider_MoveFSM::diagonalDownRight;
	else
		this->spiderState = &Spider_MoveFSM::diagonalDownLeft;

#endif
#if false
	//todo: the scale setting and rotation is silly for now. fix later
	if (pos.x == 0) //spawn on left
	{
		this->sprite.setScale(-1.f, -1.f);
		if (this->sprite.getRotation() == 0)
			//ConsoleMsg::WriteLine("left incorrect");
			this->sprite.setRotation(180.f);
	}

	else
		this->sprite.setScale(-1.f, -1.f);

#endif

	this->sprite.setScale(1.4f, 1.4f);
	RegisterCollision<Spider>(*this);

}

void Spider::Collision(Bullet *bullet)
{
	bullet->RemoveBullet();
	RemoveSpider();
	ScoreManager::SendScoreCmd(this->pDeath);
}

void Spider::Collision(Mushroom *shroom)
{
#if SPIDER_CHANGE
	//have the spider change to opposite directions when it collides with a shroom
	if (upOrDown == SpiderDirection::Down)
		upOrDown = SpiderDirection::Up;
	else
		upOrDown = SpiderDirection::Down;

#elif !SPIDER_CHANGE


#endif

	shroom->RemoveMushroom();
}

void Spider::Collision(Ship * ship)
{
	ship->DestroyShip();
}

void Spider::RemoveSpider()
{
	this->active = false;
	this->DeregisterCollision<Spider>(*this);
	this->sprite.setScale(0.f, 0.f);

	SpiderManager::RemoveSpider(this);
}
