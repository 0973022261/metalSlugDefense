#include "stdafx.h"
#include "pixelCollisionTest.h"


pixelCollisionTest::pixelCollisionTest()
{
}


pixelCollisionTest::~pixelCollisionTest()
{
}

HRESULT pixelCollisionTest::init()
{
	//¾ð´ö ÀÌ¹ÌÁö ¼ÂÆÃ
	IMAGEMANAGER->addImage("¾ð´ö", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_ball = IMAGEMANAGER->addImage("°ø", "ball.bmp", 60, 60, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 100;
	_y = WINSIZEY / 2 + 100;

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	//Å½»çÃà -> 
	_probeY = _y + _ball->getHeight() / 2;



	return S_OK;
}

void pixelCollisionTest::release()
{

}

void pixelCollisionTest::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 2.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 2.0f;
	}

	//Å½»ç ÃàÀº °øÀÇ ÁÂÇ¥¸¦ µû¶ó¼­ °è¼Ó °»½ÅÇØÁØ´Ù
	_probeY = _y + _ball->getHeight() / 2;

	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("¾ð´ö")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->getHeight() / 2;
			break;
		}
	}




	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

}

void pixelCollisionTest::render()
{
	IMAGEMANAGER->findImage("¾ð´ö")->render(getMemDC());

	_ball->render(getMemDC(), _rc.left, _rc.top);
}