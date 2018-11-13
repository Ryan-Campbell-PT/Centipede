#include "UserInputManager.h"
#include "Glyph.h"
#include "TextEditor.h"
#include "GameGrid.h"
#include "GameManager.h"

UserInputManager * UserInputManager::instance = nullptr;

void UserInputManager::RequestUsername()
{
	GetInstance();
}

void UserInputManager::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}

UserInputManager::UserInputManager()
	:currentInput(""), maxGlyphs(3), curNumGlyphs(0)
{
	this->startingPos = sf::Vector2f(WindowManager::MainWindow.getSize().x / 2, WindowManager::MainWindow.getSize().y / 2 + SPRITE_SIZE);
	userGlyph = new Glyph[maxGlyphs];
	this->RegisterInput();

	
	std::string youWon = "You won enter your name";
	sf::Vector2f wonPos = sf::Vector2f(WindowManager::MainWindow.getSize().x / 7, WindowManager::MainWindow.getSize().y / 2);
	for(int i = 0; i < youWon.size(); i++)
	{
		this->youWonList.push_back(TextEditor::WriteText(youWon.at(i), wonPos));
		wonPos.x += SPRITE_SIZE;
	}
}

UserInputManager* UserInputManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new UserInputManager;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void UserInputManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if(this->curNumGlyphs >= this->maxGlyphs && k != sf::Keyboard::BackSpace && k != sf::Keyboard::Enter)
		return;

	switch (k)
	{
	case sf::Keyboard::A:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('A', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'A';
		startingPos.x += SPRITE_SIZE;
		break;


	case sf::Keyboard::B:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('B', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'B';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::C:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('C', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'C';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::D:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('D', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'D';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::E:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('E', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'E';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::F:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('F', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'F';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::G:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('G', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'G';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::H:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('H', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'H';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::I:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('I', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'I';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::J:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('J', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'J';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::K:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('K', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'K';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::L:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('L', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'L';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::M:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('M', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'M';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::N:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('N', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'N';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::O:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('O', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'O';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::P:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('P', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'P';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::Q:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('Q', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'Q';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::R:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('R', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'R';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::S:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('S', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'S';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::T:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('T', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'T';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::U:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('U', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'U';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::V:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('V', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'V';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::W:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('W', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'W';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::X:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('X', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'X';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::Y:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('Y', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'Y';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::Z:
		this->userGlyph[this->curNumGlyphs] = TextEditor::WriteText('Z', startingPos);
		this->curNumGlyphs++;
		this->currentInput += 'Z';
		startingPos.x += SPRITE_SIZE;
		break;

	case sf::Keyboard::BackSpace:
		this->currentInput.erase(this->curNumGlyphs);
		this->curNumGlyphs--;
		this->startingPos.x -= SPRITE_SIZE;
		break;

	case sf::Keyboard::Enter: //this will confirm your selection
		HighScoreManager::SetCurrentUserName(this->currentInput);
		this->DeregisterInput(); //dont take input any longer
		GameManager::EndGame();
		break;

	default:
		break;
	}
}

void UserInputManager::Draw()
{
	for (unsigned int i = 0; i < curNumGlyphs; i++)
		userGlyph[i].Draw();

	for(auto f : this->youWonList)
		f.Draw();
}
