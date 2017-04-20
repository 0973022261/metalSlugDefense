#include "stdafx.h"
#include "starcraftScene.h"
#include "battle.h"

starcraftScene::starcraftScene()
{
}


starcraftScene::~starcraftScene()
{
}

HRESULT starcraftScene::init()
{
	_shipManager = new shipManager;
	_shipManager->init();

	return S_OK;
}

void starcraftScene::release()
{

}

void starcraftScene::update()
{
	_shipManager->update();
}

void starcraftScene::render()
{
	_shipManager->render();
}