#include "Mushroom.h"
#include "MushroomFactory.h"
#include "GameGrid.h"

Mushroom::Mushroom(sf::Vector2f v)
{

	//handle collision and sprite management first
	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); //4 and 2 show the first mushroom, undamaged
	SetCollider(sprite, bitmap, true);
	RegisterCollision<Mushroom>(*this);
	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	//then handle positioning and housekeeping

	//this purpose is hard coded for now, 36 because the first level of the map shouldnt
	//have any mushrooms, its avaliable for the centi only
	//if (v.y < 48)
	//	v.y = 48;

	////for sprite purposes, we set it to be 12 so the sprite doesnt go off the window
	//if (v.x < 36)
	//	v.x = 36;
	
	this->SetPosition(v);
	
	this->state = MushroomState::Healthy;
}

Mushroom::Mushroom(float x, float y)
{
	this->bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2); //4 and 2 show the first mushroom, undamaged
	this->sprite.setScale(1.5f, 1.5f);
#if false
	MushroomFactory::instance->GetNewMushroomPosition(sf::Vector2f(x, y));

	

#elif true
	SetPosition(sf::Vector2f(x, y));
#endif
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void Mushroom::TakeDamage()
{
	//progress the health of the mushroom, while also moving the animation one forward
	this->sprite.SetAnimation(health, ++health);

	if (health % 4 == 0) //modulous to compensate for poison or healthy
		MushroomFactory::GetInstance()->RecycleMushroom(this);

	//this->MainSprite.SetAnimation(1, 2); //second mushroom state
	//this->MainSprite.SetAnimation(2, 3); //third mushroom state
	//this->MainSprite.SetAnimation(3, 4); //fourth mushroom state
}

void Mushroom::ChangeState(MushroomState state)
{
	this->state = state;

	if (state == MushroomState::Poison)
		this->health += 4; //+= incase the mushroom is damaged
	else if (state == MushroomState::Healthy) //will likely never be called, but just to be sure
		this->health -= 0; //-= incase the mushroom is damaged

	this->sprite.SetAnimation(health, health);

	
	ConsoleMsg::WriteLine("Mushroom Pos: " + std::to_string(this->position.x) + " " + std::to_string(this->position.y));
}

MushroomState Mushroom::GetState()
{
	return this->state;
}

Mushroom::~Mushroom()
{
}

void Mushroom::SetPosition(sf::Vector2f v)
{
	GameGrid::GetInstance()->GetCenterGridPosition(v);
	this->sprite.setPosition(v);
	position = v;

	this->health = 0; //setting the positions of a mushroom assumes its full health

	//return whether it can be placed there
	GameGrid::GetInstance()->SetGridStatus(v, GameGridEnum::Mushroom);
}
