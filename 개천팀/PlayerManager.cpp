#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	IMAGEMANAGER->addImage("�����ڱ⺻�Ѵ��", "�����ڱ⺻�Ѵ��.bmp", 50, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ڸ�ü�⺻", "�����ڸ�ü�⺻.bmp", 50, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "����������.bmp", 70 * 19, 70, 19, 1, true, RGB(255, 0, 255));



	return S_OK;
}

void PlayerManager::release()
{


}

void PlayerManager::render()
{


}

void PlayerManager::update()
{


}

