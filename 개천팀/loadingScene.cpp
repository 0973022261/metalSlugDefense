#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
{
}


loadingScene::~loadingScene()
{
}


HRESULT loadingScene::init()
{
	IMAGEMANAGER->findImage("loading")->setX(120);
	IMAGEMANAGER->findImage("loading")->setY(WINSIZEY - 60);

	_count = _currentFrameY = 0;

	_maxGauge = 100.0f;
	_currentGauge = 0;

	_loadingGauge = new progressBar;
	_loadingGauge->init(IMAGEMANAGER->findImage("loading")->getX() - 20, IMAGEMANAGER->findImage("loading")->getY() - 40, WINSIZEX / 2, 40);
	_loadingGauge->setGauge(_currentGauge, _maxGauge);


	return S_OK;
}

void loadingScene::release()
{

}

void loadingScene::update()
{
	_count++;
	if (_count % 10 == 0)
	{
		IMAGEMANAGER->findImage("loading")->setFrameY(++_currentFrameY);
		_currentGauge += 5;
		if (_currentFrameY > IMAGEMANAGER->findImage("loading")->getMaxFrameY())
		{
			_count = _currentFrameY = 0;
			IMAGEMANAGER->findImage("loading")->setFrameY(0);
		}
	}

	_loadingGauge->setGauge(_currentGauge, _maxGauge);


	if (_currentGauge > _maxGauge)
	{
		SCENEMANAGER->changeScene("메인화면");
	}

}

void loadingScene::render()
{

	IMAGEMANAGER->findImage("loadingBG")->render(getMemDC());
	_loadingGauge->render();
	IMAGEMANAGER->findImage("loading")->frameRender(getMemDC(), IMAGEMANAGER->findImage("loading")->getX(), IMAGEMANAGER->findImage("loading")->getY());
}
