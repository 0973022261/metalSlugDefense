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

	TIMEMANAGER->render(getMemDC());

	_zm->render();

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
