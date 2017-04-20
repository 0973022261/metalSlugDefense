#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init()
{
//	_Upperbody = IMAGEMANAGER->findImage(")
//	_Lowerbody = 
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_rc = RectMakeCenter(_x, _y, 50, 50);

	return S_OK;
}

void Player::release()
{


}

void Player::render()
{
	
	_Upperbody->render(getMemDC(), _rc.left, _rc.top - 25);
	_Lowerbody->render(getMemDC(), _rc.left, _rc.top);

}

void Player::update()
{


}
