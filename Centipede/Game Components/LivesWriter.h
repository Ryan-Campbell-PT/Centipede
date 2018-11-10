#ifndef LIVESWRITER_H
#define LIVESWRITER_H

#include "TEAL/GameObject.h"

class LivesWriter : public GameObject
{
public:
	static void WriteLives(const int &numLives);

	static void Terminate(GameObject *);

private:
	LivesWriter();
	static LivesWriter* GetInstance();
	static LivesWriter* instance;

	virtual void Draw() override;

	void writeLives(const int &numLives);

	sf::Vector2f startingPos_Lives;
	sf::Sprite spriteToDisplay;
	sf::Sprite *liveSprites; //this will be the collection of lives
	int livesToDisplay; //this is how many sprites we will show on screen
};

#endif // LIVESWRITER_H
