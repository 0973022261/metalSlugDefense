#pragma once
#include "gameNode.h"

class stage1Scene : public gameNode
{
private:
	image* _mapBG;

	POINT _ptMap;

	RECT _rcMap;
	RECT _rcMouse;

	bool _isStart;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	POINT getPtMap() const { return _ptMap; }

	stage1Scene();
	~stage1Scene();
};

