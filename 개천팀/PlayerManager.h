#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Card.h"

#include <vector>

//백터로 플레이어와 빈카드를 위치 생성 

class PlayerManager : public gameNode
{
private:
	vector<Player*> _vPlayer;
	vector<Player*>::iterator _viPlayer;

public:
	HRESULT init();
	void release();
	void render();
	void update();


//	vector<Player*> &getVPlayer() 


	PlayerManager();
	~PlayerManager();
};

