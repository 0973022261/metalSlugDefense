#pragma once
#include "gameNode.h"

class mainScene : public gameNode
{
private:
	float _cloudX;

	BYTE _alpha;

	RECT _startBtRc;
	RECT _optionBtRc;
	RECT _helpBtRc;
	RECT _quitBtRc;

	bool _isStart;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void mouse_up();

	mainScene();
	~mainScene();
};

