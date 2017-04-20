#pragma once
#include "gameNode.h"


//캐릭터들의 부모 클래스 플레이어는 마르코 에리 타마 피오 클락 에리 방패병 등 

enum playerDirection
{
	IDLE,
	ATTACK,
	DIE,



};





class Player : public gameNode
{
protected:
	//자식에게 갈 이미지 좌표 렉트 체력 데미지 등 추가  
	image* _Upperbody;         //상체만 쓰는 이미지
	image* _Lowerbody;         //하체만 쓰는 이미지
	image* _body;              //완성된 이미지 바디

	playerDirection _playerdirection;   //현재 상태


	int _Hp;

	int _Damege;



	float _x;                
	float _y;
	RECT _rc;
	


public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();



	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setRect(RECT rc) { _rc = rc; }


	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRect() { return _rc; }


	Player();
	~Player();
};

