#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _image;		//에너미 이미지
	RECT _rc;			//에너미 렉트

	int _currentFrameX;	//에너미 현재 프레임 이미지
	int _currentFrameY;	

	int _count;			//발사 딜레이를 위한 카운트
	int _fireCount;		//발사 카운트
	int _rndFireCount;	//랜덤하게 발사시킬 카운트

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

