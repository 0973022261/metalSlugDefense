#pragma once
#include "gameNode.h"
#include "knight.h"

class ghostnGoblinsScene : public gameNode
{
private:
	knight* _knight;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	ghostnGoblinsScene();
	~ghostnGoblinsScene();
};

