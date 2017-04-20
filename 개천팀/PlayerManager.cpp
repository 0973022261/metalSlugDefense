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
	IMAGEMANAGER->addImage("마르코기본총대기", "마르코기본총대기.bmp", 50, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("마르코몸체기본", "마르코몸체기본.bmp", 50, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마르코죽음", "마르코죽음.bmp", 70 * 19, 70, 19, 1, true, RGB(255, 0, 255));



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

