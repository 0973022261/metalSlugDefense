#pragma once
#include "gameNode.h"


//ĳ���͵��� �θ� Ŭ���� �÷��̾�� ������ ���� Ÿ�� �ǿ� Ŭ�� ���� ���к� �� 



class Player : public gameNode
{
protected:
	//�ڽĿ��� �� �̹��� ��ǥ ��Ʈ ü�� ������ �� �߰�  



public:
	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	Player();
	~Player();
};

