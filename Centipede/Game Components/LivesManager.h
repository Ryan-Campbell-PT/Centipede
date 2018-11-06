#ifndef LIVESMANAGER_H
#define LIVESMANAGER_H

#include "TEAL/CommonElements.h"

class LivesManager : public GameObject
{
public:
	static void DisplayLives(const int &lives);
	static int GetStartingLives();

private:
	LivesManager();
	static LivesManager* GetInstance();

	virtual void Draw() override;

	int maxNumLives;
	int currentNumLives;
	sf::Sprite spriteToDisplay;
	sf::Sprite *liveSprites;
	sf::Vector2f startingPos_Lives;
	static LivesManager* instance;
};

#endif // LIVESMANAGER_H
