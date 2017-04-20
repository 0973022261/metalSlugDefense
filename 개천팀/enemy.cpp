#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{

}

HRESULT enemy::init()
{

	return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;

	_rndFireCount = RND->getFromIntTo(1, 1000);

	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth(), _image->getFrameHeight());




	return S_OK;
}

void enemy::release()
{

}

void enemy::update() 
{
	_count++;

	if (_count % 2 == 0)
	{
		_image->setFrameX(_image->getFrameX() + 1);
		_currentFrameX++;
		if (_currentFrameX >= _image->getMaxFrameX()) _currentFrameX = 0;
	}
}

void enemy::render() 
{
	draw();
}


void enemy::move()
{

}


void enemy::draw()
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}


bool enemy::bulletCountFire()
{
	_fireCount++;

	//발사시간이 됐다!
	if (_fireCount % _rndFireCount == 0)
	{
		_fireCount = 0;
		_rndFireCount = RND->getFromIntTo(1, 1000);

		//쏘라고 명령주라
		return true;
	}

	//항시 꺼두자
	return false;
}
