#include "Spider.h"
#include <random>

//TODO: turn gameobjects functions into the Destory() and Initalize() GO objects
Spider::Spider()
{
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);

	this->sprite.setScale(0.f, 0.f);

	SetCollider(sprite, bitmap, true);

	this->active = false;
}

Spider::~Spider()
{
}

void Spider::Update()
{
	if (!active)
		return;

#if false

	++randomNum;

	//todo: terrible if statements ahead, im aware, will fix in future
	if(this->randomNum > RANDOM_CHANGE_NUM) //this will add some randomness to the spider
		if (this->upOrDown == SpiderDirection::Up)
			this->upOrDown = SpiderDirection::Down;

		else
			this->upOrDown = SpiderDirection::Up;


	if (this->leftOrRight == SpiderDirection::Left)
	{
		this->position.x -= Game::FrameTime() * SPEED;

		if (this->position.x < 0)
			RemoveSpider();
	}

	else if (this->leftOrRight == SpiderDirection::Right)
	{
		this->position.x -= Game::FrameTime() * SPEED;

		if (this->position.x > WindowManager::MainWindow.getSize().x)
			RemoveSpider();
	}

	else {} //this is if its vertical, where it wont be changing the x axis at all

	if (this->upOrDown == SpiderDirection::Up)
		this->position.y += Game::FrameTime() * SPEED;

	else 
		this->position.y -= Game::FrameTime() * SPEED;
#endif

	this->sprite.setPosition(this->position);

}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Spider::SpawnSpider(sf::Vector2f pos)
{

	
#if false
	this->position = pos;
	this->sprite.setPosition(pos);

	this->active = true;
	this->randomNum = rand() % RANDOM_CHANGE_NUM;

	if (pos.x == 0) //spawning on left
		this->leftOrRight = SpiderDirection::Left;
	else
		this->leftOrRight = SpiderDirection::Right;
#elif true
	this->position.x = 200;// = WindowManager::MainWindow.getSize().x / 2;
	this->position.y = 200;// WindowManager::MainWindow.getSize().y / 2;
	this->sprite.setPosition(position);
	this->active = true;

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

	this->sprite.setScale(1.3f, 1.3f);
	RegisterCollision<Spider>(*this);

}

void Spider::Collision(Bullet *)
{
	RemoveSpider();
}

void Spider::Collision(Mushroom *)
{
	//have the spider change to opposite directions when it collides with a shroom
	if (upOrDown == SpiderDirection::Down)
		upOrDown = SpiderDirection::Up;
	else
		upOrDown = SpiderDirection::Down;
}

void Spider::RemoveSpider()
{
	this->active = false;
	this->DeregisterCollision<Spider>(*this);
	this->sprite.setScale(0.f, 0.f);
}
