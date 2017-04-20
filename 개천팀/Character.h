#pragma once
#include "Player.h"

//캐릭터들을 여기에 플레이어 자식 클래스를 생성

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

