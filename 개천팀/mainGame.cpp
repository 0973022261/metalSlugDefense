#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//������ �Ҹ��� ���̺���
////////////////////////////////////

//�ʱ�ȭ ���ִ� �Լ�
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	addImage();

	SCENEMANAGER->addLoadingScene("�ε�", new loadingScene);
	SCENEMANAGER->addScene("����ȭ��", new mainScene);
	SCENEMANAGER->addScene("stage1", new stage1Scene);

	SCENEMANAGER->changeScene("�ε�");


	_zm = new zombieManager;
	_zm->init();

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();
	_zm->release();
}

//���� �ϴ� ��
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

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	_zm->render();

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}



void mainGame::addImage()
{
	IMAGEMANAGER->addImage("loadingBG", "bmp\\BGimage\\�ε�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mainBG", "bmp\\BGimage\\��Ʈ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudBG", "bmp\\BGimage\\����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage1BG", "bmp\\BGimage\\stage1.bmp", (WINSIZEX * 2)*1.5, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blackBG", "bmp\\BGimage\\����ȭ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("loading", "bmp\\etc\\loading.bmp", 211, 68, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("startBt", "bmp\\etc\\startBt.bmp", 358, 461, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("optionBt", "bmp\\etc\\optionBt.bmp", 98, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("helpBt", "bmp\\etc\\helpBt.bmp", 55, 50, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("quitBt", "bmp\\etc\\quitBt.bmp", 55, 60, 1, 2, true, RGB(255, 0, 255));
}