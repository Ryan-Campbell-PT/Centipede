#include "Mushroom.h"
#include "Bullet.h"
#include "MushroomFactory.h"
#include "GameGrid.h"

Mushroom::Mushroom(sf::Vector2f v)
{
	//this purpose is hard coded for now, 36 because the first level of the map shouldnt
	//have any mushrooms, its avaliable for the centi only
	if (v.y < 36)
		v.y = 36;

	//for sprite purposes, we set it to be 12 so the sprite doesnt go off the window
	if (v.x < 13)
		v.x = 13;

	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	
	//4 and 2 show the first mushroom, undamaged
	this->MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); 

	//this->MainSprite.SetAnimation(1, 2); //second mushroom state
	//this->MainSprite.SetAnimation(2, 3); //third mushroom state
	//this->MainSprite.SetAnimation(3, 4); //fourth mushroom state

	this->SetPosition(v);

	this->MainSprite.setScale(1.5f, 1.5f);
	
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Mushroom>(*this);

	this->health = 0;


}

Mushroom::Mushroom(sf::Vector2i v)
{

	//24 because thats the hard coded scale size
	Mushroom(sf::Vector2f((float)v.x * 24, (float)v.y * 24));
}

void Mushroom::Update()
{
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(this->MainSprite);
}

void Mushroom::TakeDamage()
{
	//progress the health of the mushroom, while also moving the animation one forward
	this->MainSprite.SetAnimation(health, ++health);
	
	if (health % 4 == 0) //modulous to compensate for poison or healthy
		MushroomFactory::RecycleMushroom(this);
}

Mushroom::~Mushroom()
{
}

bool Mushroom::SetPosition(sf::Vector2f v)
{
	this->MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	this->MainSprite.setPosition(v);
	Pos = v;

	//return whether it can be placed there
	return GameGrid::GetInstance()->SetGridStatus(v, GameGridEnum::Mushroom);
}
