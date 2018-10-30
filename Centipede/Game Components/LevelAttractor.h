#ifndef _Level_Attractor
#define _Level_Attractor

#include "TEAL/CommonElements.h"

class LevelAttractor : public Scene, public GameObject
{
public:
	LevelAttractor();
	virtual void Initialize() override;
	///to determine when to swap to the next level
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey) override;
};

#endif _Level_Attractor