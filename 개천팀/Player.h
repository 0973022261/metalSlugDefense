#pragma once
#include "gameNode.h"


//캐릭터들의 부모 클래스 플레이어는 마르코 에리 타마 피오 클락 에리 방패병 등 



class Player : public gameNode
{
protected:
	//자식에게 갈 이미지 좌표 렉트 체력 데미지 등 추가  



public:
	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	Player();
	~Player();
};

