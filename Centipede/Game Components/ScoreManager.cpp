#include "ScoreManager.h"
#include "ScoreValueCmd.h"
#include "ScoreByDistanceCmd.h"
#include "PlayerManager.h"
#include "TextEditor.h"
#include "Glyph.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager()
	:scoreGlyph(nullptr), maxScoreSize(6),
	attractorMode(false), currentScore(0)
{
	startingPos_Score = sf::Vector2f(WindowManager::MainWindow.getSize().x - SPRITE_SIZE * 3.f, 0.f);
	GameGrid::GetCenterGridPosition(this->startingPos_Score);
	this->scoreGlyph = new Glyph[maxScoreSize];
	this->writeZero();
}

ScoreManager * ScoreManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ScoreManager;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void ScoreManager::Draw()
{
	for (unsigned int i = 0; i < this->currentScoreSize; i++)
		this->scoreGlyph[i].Draw();
}

void ScoreManager::privProcessScore()
{
	ScoreCmd* c = nullptr;

	if (!QueueCmds.empty())
	{ //this is simply so the writeScore doesnt constantly run
		while (!QueueCmds.empty())
		{
			c = QueueCmds.front();
			c->Execute();

			QueueCmds.pop();
		}

		this->writeScore();
	}
}

void ScoreManager::writeScore()
{
	auto scoreText = Tools::ToString(this->currentScore);
	this->currentScoreSize = scoreText.size();

	auto tmpPos = this->startingPos_Score;

	for (unsigned int iter = 0; iter < currentScoreSize; ++iter)
	{
		//simply change the contents of the array to the numbers in the given score

		this->scoreGlyph[iter] = TextEditor::WriteText(scoreText.at(currentScoreSize - iter - 1), tmpPos);

		tmpPos.x -= SPRITE_SIZE;
	}

	HighScoreManager::AddScore(this->currentScore);
}

void ScoreManager::writeZero()
{
	const std::string zeroZero = "00";
	auto tmpPos = startingPos_Score;
	this->currentScoreSize = zeroZero.size();

	for (unsigned int iter = 0; iter < currentScoreSize; ++iter)
	{
		//simply change the contents of the array to the numbers in the given score

		this->scoreGlyph[iter] = TextEditor::WriteText(zeroZero[iter], tmpPos);

		tmpPos.x -= SPRITE_SIZE;
	}


}

void ScoreManager::AddScore(int val)
{
	GetInstance()->currentScore += val;
}

ScoreCmd * ScoreManager::GetScoreCommand(const ScoreEvents &ev)
{
	ScoreCmd* pCmd = nullptr;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = new ScoreValueCmd(FleaDeath);
		break;

	case ScoreEvents::ScorpionKilled:
		pCmd = new ScoreValueCmd(ScorpionDeath);
		break;

	case ScoreEvents::MushroomKilled:
		pCmd = new ScoreValueCmd(MushroomDeath);
		break;

	case ScoreEvents::SpiderKilled:
		pCmd = new ScoreByDistanceCmd(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;

	case ScoreEvents::MushroomPoisonKilled:
		pCmd = new ScoreValueCmd(MushroomPoisonDeath);
		break;

	case ScoreEvents::CentiHeadKilled:
		pCmd = new ScoreValueCmd(CentiHeadDeath);
		break;

	case ScoreEvents::CentiBodyKilled:
		pCmd = new ScoreValueCmd(CentiBodyDeath);
		break;

	default:
		break;
	}

	return pCmd;
}

void ScoreManager::SendScoreCmd(ScoreCmd * c)
{
	//attractor mode doesnt count score, so just dont bother adding them
	if (GetInstance()->attractorMode)
		return;

	instance->QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	GetInstance()->privProcessScore();
}

void ScoreManager::SetCurrentScore(const int score)
{
	GetInstance()->currentScore = score;
}

int ScoreManager::GetCurrentScore()
{
	return GetInstance()->currentScore;
}

void ScoreManager::AttractorMode(bool b)
{
	GetInstance()->attractorMode = b;
}

void ScoreManager::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}
