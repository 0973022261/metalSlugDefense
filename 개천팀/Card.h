#pragma once
#include "gameNode.h"

//��ī�� ��ǥ�� �̹���

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

