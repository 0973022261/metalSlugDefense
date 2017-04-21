#pragma once
#include "gameNode.h"
#include "progressBar.h"

class loadingScene : public gameNode
{
private:
	int _count, _currentFrameY;

	progressBar* _loadingGauge;
	float _maxGauge, _currentGauge;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	loadingScene();
	~loadingScene();
};

