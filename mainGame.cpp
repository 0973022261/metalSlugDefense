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
	gameNode::init();

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

}

//�׷��ִ� ��
void mainGame::render(HDC hdc)
{

}
