#include "stdafx.h"
#include "effectTest.h"


effectTest::effectTest()
{
}


effectTest::~effectTest()
{

}

HRESULT effectTest::init()
{
	IMAGEMANAGER->addImage("빠이야", "explosion.bmp", 0, 0, 832, 62, true, RGB(255, 0, 255));


	_effect = new effect;
	_effect->init(IMAGEMANAGER->findImage("빠이야"), 32, 62, 1, 1.0f);

	_count = 0;

	EFFECTMANAGER->addEffect("빠이야", "explosion.bmp", 832, 62, 32, 62, 1, 0.2f, 300);

	return S_OK;
}

void effectTest::release()
{

}

void effectTest::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_effect->startEffect(_ptMouse.x, _ptMouse.y);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		EFFECTMANAGER->play("빠이야", _ptMouse.x, _ptMouse.y);
	}

	/*
	_count++;

	if (_count % 30 == 0)
	{
		_effect->startEffect(RND->getFromIntTo(10, WINSIZEX - 10), RND->getFromIntTo(10, WINSIZEY - 10));


		_count = 0;
	}
	*/
	EFFECTMANAGER->update();
	_effect->update();
}

void effectTest::render() 
{
	EFFECTMANAGER->render();
	_effect->render();
}
