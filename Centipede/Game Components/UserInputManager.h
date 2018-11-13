#ifndef USERINPUTMANAGER_H
#define USERINPUTMANAGER_H

#include <string>
#include "TEAL/CommonElements.h"

class Glyph;

class UserInputManager : public GameObject
{
public:
	static void RequestUsername();
	static void Terminate(GameObject*);

private:
	UserInputManager();
	static UserInputManager *GetInstance();
	static UserInputManager *instance;

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey) override;
	virtual void Draw() override;

	Glyph *userGlyph;
	std::vector<Glyph> youWonList;
	std::string currentInput;
	sf::Vector2f startingPos;
	unsigned int maxGlyphs;
	unsigned int curNumGlyphs;
};

#endif // USERINPUTMANAGER_H
