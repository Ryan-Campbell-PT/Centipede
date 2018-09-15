#include "Mushroom.h"
#include "Bullet.h"

Mushroom::Mushroom(sf::Vector2f v)
{
	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	
	//4 and 2 show the first mushroom, undamaged
	this->MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); 
	
	//this->MainSprite.SetAnimation(1, 2); //second mushroom state
	//this->MainSprite.SetAnimation(2, 3); //third mushroom state
	//this->MainSprite.SetAnimation(3, 4); //fourth mushroom state

	this->SetPosition(v);

	this->MainSprite.setScale(1.5f, 1.5f);
}

void Mushroom::Update()
{
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(this->MainSprite);
}

void Mushroom::Collision(Bullet * b)
{
	ConsoleMsg::WriteLine("Bulelt");
}

Mushroom::~Mushroom()
{
}

bool Mushroom::SetPosition(sf::Vector2f v)
{
	this->MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	this->MainSprite.setPosition(v);
	Pos = v;
	return true;
}
