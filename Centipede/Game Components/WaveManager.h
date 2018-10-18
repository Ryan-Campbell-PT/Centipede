#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

class WaveManager
{
public:
	static void GetWaveInfo(const char* filePath);
	
private:
	WaveManager *GetInstance();

	WaveManager* instance;

	unsigned int currentLevel;
};

#endif // WAVEMANAGER_H
