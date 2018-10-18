#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

class WaveManager
{
public:
	
private:
	WaveManager *GetInstance();
	void GetWaveInfo(const char* filePath);

	WaveManager* instance;

	unsigned int currentLevel;
};

#endif // WAVEMANAGER_H
