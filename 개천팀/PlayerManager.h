#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Card.h"

#include <vector>

//���ͷ� �÷��̾�� ��ī�带 ����

class PlayerManager : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void render();
	void update();



	PlayerManager();
	~PlayerManager();
};

