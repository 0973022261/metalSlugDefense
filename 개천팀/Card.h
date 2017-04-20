#pragma once
#include "gameNode.h"

//빈카드 좌표와 이미지

class Card : public gameNode
{
private:



public:
	HRESULT init(void);
	void release();
	void render();
	void update();

	Card();
	~Card();
};

