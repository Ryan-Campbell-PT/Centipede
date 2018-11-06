#ifndef LIVESMANAGER_H
#define LIVESMANAGER_H

#include "TEAL/CommonElements.h"

class LivesManager : public GameObject
{
public:
	static void DisplayLives(const int &lives);

private:
	LivesManager();
	static LivesManager* GetInstance();

	virtual void Draw();

	int maxNumLives;
	int currentNumLives;
	sf::Sprite spriteToDisplay;
	sf::Sprite *liveSprites;
	sf::Vector2f startingPos_Lives;
	static LivesManager* instance;
};

#endif // LIVESMANAGER_H
