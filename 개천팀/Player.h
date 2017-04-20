#pragma once
#include "gameNode.h"


//ĳ���͵��� �θ� Ŭ���� �÷��̾�� ������ ���� Ÿ�� �ǿ� Ŭ�� ���� ���к� �� 

enum playerDirection
{
	IDLE,
	ATTACK,
	DIE,



};





class Player : public gameNode
{
protected:
	//�ڽĿ��� �� �̹��� ��ǥ ��Ʈ ü�� ������ �� �߰�  
	image* _Upperbody;         //��ü�� ���� �̹���
	image* _Lowerbody;         //��ü�� ���� �̹���
	image* _body;              //�ϼ��� �̹��� �ٵ�

	playerDirection _playerdirection;   //���� ����


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

