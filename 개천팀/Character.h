#pragma once
#include "Player.h"

//ĳ���͵��� ���⿡ �÷��̾� �ڽ� Ŭ������ ����

class Marco : public Player
{
public:

	HRESULT init();
	void release();
	void render();
	void update();


	Marco();
	~Marco();
};

