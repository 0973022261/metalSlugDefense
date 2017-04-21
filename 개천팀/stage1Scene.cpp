#include "stdafx.h"
#include "stage1Scene.h"


stage1Scene::stage1Scene()
{
}


stage1Scene::~stage1Scene()
{
}


HRESULT stage1Scene::init()
{
	_mapBG = IMAGEMANAGER->findImage("stage1BG");

	_ptMap.x = 0;
	_ptMap.y = 0;

	_rcMap = RectMakeCenter(_ptMap.x / 2, _ptMap.y + WINSIZEY/2, 50, 50);
	_rcMouse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 50, 50);

	_isStart = false;


	return S_OK;
}

void stage1Scene::release()
{

}

void stage1Scene::update()
{
	if (!(_isStart))
	{
		if (_ptMap.x + 50 < WINSIZEX * 2)	_ptMap.x += 10;
		else _isStart = true;
	}
	else if (_ptMouse.x < 50)
	{
		if (_ptMap.x > 500) _ptMap.x -= 10;
	}
	else if (_ptMouse.x > WINSIZEX - 50)
	{
		if (_ptMap.x < (WINSIZEX * 2) - 600) _ptMap.x += 10;
	}

	_rcMap = RectMakeCenter(_ptMap.x / 2, _ptMap.y + WINSIZEY / 2, 50, 50);
	_rcMouse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 50, 50);

}

void stage1Scene::render()
{
	IMAGEMANAGER->findImage("stage1BG")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _ptMap.x, _ptMap.y);

	Rectangle(getMemDC(), _rcMap.left, _rcMap.top, _rcMap.right, _rcMap.bottom);
	Rectangle(getMemDC(), _rcMouse.left, _rcMouse.top, _rcMouse.right, _rcMouse.bottom);
}
