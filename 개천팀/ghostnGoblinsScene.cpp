#include "stdafx.h"
#include "ghostnGoblinsScene.h"


ghostnGoblinsScene::ghostnGoblinsScene()
{
}


ghostnGoblinsScene::~ghostnGoblinsScene()
{
}

HRESULT ghostnGoblinsScene::init()
{
	_knight = new knight;
	_knight->init();

	return S_OK;
}

void ghostnGoblinsScene::release()
{

}

void ghostnGoblinsScene::update()
{
	_knight->update();
}

void ghostnGoblinsScene::render()
{
	_knight->render();
}