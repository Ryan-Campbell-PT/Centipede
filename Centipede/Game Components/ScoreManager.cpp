#include "ScoreManager.h"
#include "ScoreValueCmd.h"
#include "ScoreByDistanceCmd.h"
#include "PlayerManager.h"
#include "TextEditor.h"
#include "Glyph.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager()
	:scoreGlyph(nullptr), maxScoreSize(6),
	startingPos_Score(WindowManager::MainWindow.getSize().x - SPRITE_SIZE * 3, 0),
	currentScore(0)
{
	this->scoreGlyph = new Glyph[maxScoreSize];
	this->writeZero();
}

ScoreManager * ScoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ScoreManager;

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
		//todo: may want to send to HighScoreManager to make middle one dynamic
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

ScoreCmd * ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	ScoreCmd* pCmd = nullptr;
	printf("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		printf("FleaDeath\n");
		pCmd = new ScoreValueCmd(FleaDeath);
		break;

	case ScoreEvents::ScorpionKilled:
		printf("ScorpionDeath\n");
		pCmd = new ScoreValueCmd(ScorpionDeath);
		break;

	case ScoreEvents::MushroomKilled:
		printf("MushroomDeath\n");
		pCmd = new ScoreValueCmd(MushroomDeath);
		break;

	case ScoreEvents::SpiderKilled:
		printf("SpiderDeath\n");
		pCmd = new ScoreByDistanceCmd(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;

	case ScoreEvents::MushroomPoisonKilled:
		printf("MushroomPoisonDeath\n");
		pCmd = new ScoreValueCmd(MushroomPoisonDeath);
		break;

	case ScoreEvents::CentiKilled:
		printf("CentiDeath\n");
		pCmd = new ScoreValueCmd(centiDeath);
		break;

	default:
		printf("<nothing>\n");
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
