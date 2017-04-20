#include "stdafx.h"
#include "camel.h"


camel::camel()
{
}


camel::~camel()
{
}

HRESULT camel::init()
{
	//낙타 이미지
	_camel = IMAGEMANAGER->addImage("camel", "camel.bmp", 300, 267, true, RGB(255, 0, 255));

	//디폴트 애니
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani1->setDefPlayFrame(true, false);
	_ani1->setFPS(1);


	//배열 애니
	int arrAni[] = { 0, 2, 4, 6, 8, 10, 9, 7, 3,5, 1 };
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani2->setPlayFrame(arrAni, 11, true);
	_ani2->setFPS(1);


	//구간반복 애니
	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani3->setPlayFrame(3, 7, false);
	_ani3->setFPS(1);


	return S_OK;
}

void camel::release()
{

}

void camel::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_ani1->start();
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_ani2->start();
	}

	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		_ani3->start();
	}

	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 50);
	_ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);

}

void camel::render()
{

	_camel->aniRender(getMemDC(), 100, 200, _ani1);
	_camel->aniRender(getMemDC(), 300, 200, _ani2);
	_camel->aniRender(getMemDC(), 500, 200, _ani3);

}