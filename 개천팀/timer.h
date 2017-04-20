#pragma once
class timer
{
private:
	bool _isHardware;
	float _timeScale;
	float _timeElapsed;

	//int		== 호환이 가능한 정수
	//long		== 32비트 고정
	//DWORD		== 메모리값 고정

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;

public:
	HRESULT init(void);
	void tick(float lockFPS = 0.0f);
	unsigned long getFrameRate(char* str = NULL) const;
	
	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }



	timer();
	~timer();
};

