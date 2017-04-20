#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{
}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	_btnSceneChange->init("button", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_btnAngleUp = new button;
	_btnAngleUp->init("button", WINSIZEX / 2 - 100, WINSIZEY / 2 + 100,
		PointMake(0, 1), PointMake(0, 0), cbAngleUp);


	_btnAngleDown = new button;
	_btnAngleDown->init("button", WINSIZEX / 2 + 100, WINSIZEY / 2 + 100,
		PointMake(0, 1), PointMake(0, 0), cbAngleDown);



	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update()
{
	_btnSceneChange->update();
	_btnAngleUp->update();
	_btnAngleDown->update();

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("½ºÅ¸¾À");
	}
}

void selectScene::render()
{
	_btnSceneChange->render();
	_btnAngleUp->render();
	_btnAngleDown->render();

}

void selectScene::cbSceneChange(void)
{
	SCENEMANAGER->changeScene("½ºÅ¸¾À");
}

void selectScene::cbAngleUp(void)
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle + 0.1f);
}

void selectScene::cbAngleDown(void)
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle - 0.1f);
}