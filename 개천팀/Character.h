#pragma once
#include "Player.h"

//ĳ���͵��� ���⿡ �÷��̾� �ڽ� Ŭ������ ����

class Marco : public Player
{
private:


public:

	HRESULT init();
	void release();
	void render();
	void update();


	Marco();
	~Marco();
};

class eri : public Player
{
private:

public:

	HRESULT init();
	void release();
	void render();
	void update();


	eri();
	~eri();



};
