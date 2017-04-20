#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Card.h"

#include <vector>

//백터로 플레이어와 빈카드를 관리

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

