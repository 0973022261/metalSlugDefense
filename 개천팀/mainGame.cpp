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

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();

}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();
	

	TIMEMANAGER->getElapsedTime();
		
}

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	TIMEMANAGER->render(getMemDC());

	TextOut(getMemDC(),WINSIZEX/2,WINSIZEY/2,"���� ��õ���� �복�� ���̾�",strlen("���� ��õ���� �복�� ���̾�"));

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
