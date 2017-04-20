#include "stdafx.h"
#include "zombie.h"


zombie::zombie()
{
}


zombie::~zombie()
{
}

HRESULT zombie::init(const char* imageName, float x, float y, float speed, int attackDamage, int hp)
{
	_zombie._zombieImage = IMAGEMANAGER->findImage("imageName");
	_zombie._x = x;
	_zombie._y = y;
	_zombie._speed = speed;
	_zombie._rc = RectMakeCenter(x, y, _zombie._zombieImage->getFrameWidth(), _zombie._zombieImage->getFrameHeight());
	_zombie._hp = hp;
	_zombie._attackDamage = attackDamage;

	return S_OK;
}

void zombie::release()
{

}

void zombie::update()
{
	move();
}

void zombie::render()
{
	_zombie._zombieImage->frameRender(getMemDC(), _zombie._x, _zombie._y);
}

void zombie::move()
{
	_zombie._x -= _zombie._speed;
}

