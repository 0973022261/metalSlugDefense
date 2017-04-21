#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//생성자 소멸자 빠이빠이
////////////////////////////////////

//초기화 해주는 함수
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	addImage();

	SCENEMANAGER->addLoadingScene("로딩", new loadingScene);
	SCENEMANAGER->addScene("메인화면", new mainScene);
	SCENEMANAGER->addScene("stage1", new stage1Scene);

	SCENEMANAGER->changeScene("로딩");


	_zm = new zombieManager;
	_zm->init();

	return S_OK;
}

//메모리 해제함수
void mainGame::release(void)
{
	gameNode::release();
	_zm->release();
}

//연산 하는 곳
void mainGame::update(void)
{
	gameNode::update();
	
	SCENEMANAGER->update();

	_zm->update();

	TIMEMANAGER->getElapsedTime();
	
	if (RND->getFromIntTo(0, 1000) == 0)
	{
		_zm->makeZombie(WINSIZEX, RND->getFromIntTo(0, WINSIZEY), RND->getFromIntTo(0, 10));
	}
}

//그려주는 곳
void mainGame::render()
{
	//흰색 도화지 한장이 필요함
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	_zm->render();

	//백버퍼에 옮겨 그려줄 애 건들지마라 얘는
	this->getBackBuffer()->render(getHDC(), 0, 0);

}



void mainGame::addImage()
{
	IMAGEMANAGER->addImage("loadingBG", "bmp\\BGimage\\로딩.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mainBG", "bmp\\BGimage\\인트로.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudBG", "bmp\\BGimage\\구름.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage1BG", "bmp\\BGimage\\stage1.bmp", (WINSIZEX * 2)*1.5, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blackBG", "bmp\\BGimage\\검은화면.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("loading", "bmp\\etc\\loading.bmp", 211, 68, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("startBt", "bmp\\etc\\startBt.bmp", 358, 461, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("optionBt", "bmp\\etc\\optionBt.bmp", 98, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("helpBt", "bmp\\etc\\helpBt.bmp", 55, 50, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("quitBt", "bmp\\etc\\quitBt.bmp", 55, 60, 1, 2, true, RGB(255, 0, 255));
}