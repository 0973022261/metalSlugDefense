#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _image;		//���ʹ� �̹���
	RECT _rc;			//���ʹ� ��Ʈ

	int _currentFrameX;	//���ʹ� ���� ������ �̹���
	int _currentFrameY;	

	int _count;			//�߻� �����̸� ���� ī��Ʈ
	int _fireCount;		//�߻� ī��Ʈ
	int _rndFireCount;	//�����ϰ� �߻��ų ī��Ʈ

public:
	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	void move();

	void draw();

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }




	enemy();
	~enemy();
};

