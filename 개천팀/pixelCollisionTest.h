#pragma once
#include "gameNode.h"

class pixelCollisionTest : public gameNode
{
private:
	image* _mountain;		//언덕 이미지
	image* _ball;			//공 이미지

	RECT _rc;				//렉트

	float _x, _y;			//공 x,y

	int _probeY;			//Y축 탐사할 변수


public:
	HRESULT init();
	void release();
	void update();
	void render();

	pixelCollisionTest();
	~pixelCollisionTest();
};

