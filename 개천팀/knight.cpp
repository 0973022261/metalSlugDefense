#include "stdafx.h"
#include "knight.h"


knight::knight()
{
}


knight::~knight()
{
}

HRESULT knight::init()
{
	_image = IMAGEMANAGER->addFrameImage("knight", "knight.bmp", 0, 0, 612, 312, 9, 4, true, RGB(255, 0, 255));

	_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_angle = PI/2;
	_speed = 0;
	_gravity = 0;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//애니메이션 등록해봅시다
	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightStop", "knight", rightStop, 1, 6, true);

	int leftStop[] = { 9 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftStop", "knight", leftStop, 1, 6, true);

	int rightMove[] = { 1, 2, 3, 4, 5, 6 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightMove", "knight", rightMove, 6, 10, true);

	int leftMove[] = { 10, 11, 12, 13, 14, 15 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftMove", "knight", leftMove, 6, 10, true);

	int rightSit[] = { 18 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightSit", "knight", rightSit, 1, 10, true);

	int leftSit[] = { 27 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftSit", "knight", leftSit, 1, 10, true);

	int leftJump[] = { 31,33,34 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftJump", "knight", leftJump, 3, 10, false);

	int rightJump[] = {22,24,25 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightJump", "knight", rightJump, 3, 10, false);

	int arrRightFire[] = { 7, 8 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightFire", "knight", arrRightFire, 2, 10, false, rightFire, this);

	int arrLeftFire[] = { 16, 17 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftFire", "knight", arrLeftFire, 2, 10, false, leftFire, this);

	int arrRightSitFire[] = { 19, 20 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightSitFire", "knight", arrRightSitFire, 2, 10, false, rightSitFire, this);

	int arrLeftSitFire[] = { 28, 29 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftSitFire", "knight", arrLeftSitFire, 2, 10, false, leftSitFire, this);

	int arrLeftMoveJump[] = { 30,32 };
	KEYANIMANAGER->addArrayFrameAnimation("knightLeftMoveJump", "knight", arrLeftMoveJump, 2, 10, false);

	int arrRightMoveJump[] = { 21,23 };
	KEYANIMANAGER->addArrayFrameAnimation("knightRightMoveJump", "knight", arrRightMoveJump, 2, 10, false);

	_knightMotion = KEYANIMANAGER->findAnimation("knightRightStop");
	
	
	return S_OK;
}

void knight::release()
{

}

void knight::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_knightDirection == KNIGHTDIRECTION_RIGHT_SIT ||
			_knightDirection == KNIGHTDIRECTION_LEFT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_SIT;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightSit");
			_knightMotion->start();
		}
		else if (_knightDirection == KNIGHTDIRECTION_RIGHT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_MOVE_JUMP)
		{

		}
		else
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_MOVE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightMove");
			_knightMotion->start();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		if (_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_JUMP)
		{

		}

		else if (_knightDirection != KNIGHTDIRECTION_RIGHT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightStop");
			_knightMotion->start();
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_knightDirection == KNIGHTDIRECTION_LEFT_SIT ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_SIT;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftSit");
			_knightMotion->start();
		}
		else if (_knightDirection == KNIGHTDIRECTION_RIGHT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_MOVE_JUMP)
		{

		}
		else
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_MOVE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftMove");
			_knightMotion->start();

		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		if (_knightDirection == KNIGHTDIRECTION_LEFT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_JUMP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE_JUMP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_JUMP)
		{

		}
		else if (_knightDirection != KNIGHTDIRECTION_LEFT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_STOP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftStop");
			_knightMotion->start();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{

		if (_knightDirection == KNIGHTDIRECTION_LEFT_STOP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_SIT)
		{
			_angle = PI / 2;
			_gravity = 0;
			_knightDirection = KNIGHTDIRECTION_LEFT_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftJump");
			_knightMotion->start();
		}
		if (_knightDirection == KNIGHTDIRECTION_RIGHT_STOP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_SIT)
		{
			_angle = PI / 2;
			_gravity = 0;
			_knightDirection = KNIGHTDIRECTION_RIGHT_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightJump");
			_knightMotion->start();
		}
		if (_knightDirection == KNIGHTDIRECTION_LEFT_MOVE)
		{
			_angle = PI - (PI/4);
			_gravity = 0;
			_knightDirection = KNIGHTDIRECTION_LEFT_MOVE_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftMoveJump");
			_knightMotion->start();
		}
		if (_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE)
		{
			_angle = PI / 4;
			_gravity = 0;
			_knightDirection = KNIGHTDIRECTION_RIGHT_MOVE_JUMP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightMoveJump");
			_knightMotion->start();
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_knightDirection == KNIGHTDIRECTION_LEFT_STOP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_MOVE)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_SIT;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftSit");
			_knightMotion->start();
		}

		if (_knightDirection == KNIGHTDIRECTION_RIGHT_STOP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_SIT;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightSit");
			_knightMotion->start();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_knightDirection == KNIGHTDIRECTION_LEFT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_STOP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftStop");
			_knightMotion->start();
		}

		if (_knightDirection == KNIGHTDIRECTION_RIGHT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightStop");
			_knightMotion->start();
		}
	}



	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_knightDirection == KNIGHTDIRECTION_RIGHT_STOP ||
			_knightDirection == KNIGHTDIRECTION_RIGHT_MOVE)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_FIRE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightFire");
			_knightMotion->start();
		}
		if (_knightDirection == KNIGHTDIRECTION_LEFT_STOP ||
			_knightDirection == KNIGHTDIRECTION_LEFT_MOVE)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_FIRE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftFire");
			_knightMotion->start();
		}

		if (_knightDirection == KNIGHTDIRECTION_LEFT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_LEFT_SIT_FIRE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightLeftSitFire");
			_knightMotion->start();
		}

		if (_knightDirection == KNIGHTDIRECTION_RIGHT_SIT)
		{
			_knightDirection = KNIGHTDIRECTION_RIGHT_SIT_FIRE;
			_knightMotion = KEYANIMANAGER->findAnimation("knightRightSitFire");
			_knightMotion->start();
		}
	}

	switch (_knightDirection)
	{
		case KNIGHTDIRECTION_RIGHT_STOP : case KNIGHTDIRECTION_LEFT_STOP:
		break;

		case KNIGHTDIRECTION_RIGHT_MOVE:
			_x += KNIGHTSPEED;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
			if (_x > WINSIZEX + 10) _x = -10;
		break;
		case KNIGHTDIRECTION_LEFT_MOVE:
			_x -= KNIGHTSPEED;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
			if (_x < -10) _x = WINSIZEX + 10;
		break;
		case KNIGHTDIRECTION_LEFT_JUMP:
		{
			_gravity += 0.05f;

			_x += cosf(_angle) * KNIGHTSPEED;
			_y += -sinf(_angle) * KNIGHTSPEED + _gravity;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

			if (_y < WINSIZEY / 2 - 100)
			{
				_angle = -(PI / 2);
			}

			if (_y > WINSIZEY / 2)
			{
				_y = WINSIZEY / 2;
				_gravity = 0;
				_knightDirection = KNIGHTDIRECTION_LEFT_STOP;
				_knightMotion = KEYANIMANAGER->findAnimation("knightLeftStop");
				_knightMotion->start();
			}
		}
		break;
		case KNIGHTDIRECTION_RIGHT_JUMP:
		{
			_gravity += 0.05f;

			_x += cosf(_angle) * KNIGHTSPEED;
			_y += -sinf(_angle) * KNIGHTSPEED + _gravity;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

			if (_y < WINSIZEY / 2 - 100)
			{
				_angle = -(PI / 2);
			}

			if (_y > WINSIZEY / 2)
			{
				_y = WINSIZEY / 2;
				_gravity = 0;
				_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;
				_knightMotion = KEYANIMANAGER->findAnimation("knightRightStop");
				_knightMotion->start();
			}
		}
		break;
		case KNIGHTDIRECTION_RIGHT_MOVE_JUMP:
		{
			_gravity += 0.05f;

			_x += cosf(_angle) * KNIGHTSPEED;
			_y += -sinf(_angle) * KNIGHTSPEED + _gravity;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

			if (_y < WINSIZEY / 2 - 100)
			{
				_angle = -(PI / 4);
			}

			if (_y > WINSIZEY / 2)
			{
				_y = WINSIZEY / 2;
				_gravity = 0;
				_knightDirection = KNIGHTDIRECTION_RIGHT_STOP;
				_knightMotion = KEYANIMANAGER->findAnimation("knightRightStop");
				_knightMotion->start();
			}
		}
		break;

		case KNIGHTDIRECTION_LEFT_MOVE_JUMP:
		{
			_gravity += 0.05f;

			_x += cosf(_angle) * KNIGHTSPEED;
			_y += -sinf(_angle) * KNIGHTSPEED + _gravity;
			_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

			if (_y < WINSIZEY / 2 - 100)
			{
				_angle = -(PI - (PI / 4));
			}

			if (_y > WINSIZEY / 2)
			{
				_y = WINSIZEY / 2;
				_gravity = 0;
				_knightDirection = KNIGHTDIRECTION_LEFT_STOP;
				_knightMotion = KEYANIMANAGER->findAnimation("knightLeftStop");
				_knightMotion->start();
			}
		}
		break;
	}

	KEYANIMANAGER->update();
}

void knight::render()
{
	_image->aniRender(getMemDC(), _rc.left, _rc.top, _knightMotion);
}

void knight::rightFire(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_RIGHT_STOP);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightRightStop"));
	k->getKnightMotion()->start();
	
}

void knight::leftFire(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_LEFT_STOP);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightLeftStop"));
	k->getKnightMotion()->start();

}

void knight::rightSitFire(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_RIGHT_SIT);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightRightSit"));
	k->getKnightMotion()->start();

}

void knight::leftSitFire(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_LEFT_SIT);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightLeftSit"));
	k->getKnightMotion()->start();

}

void knight::leftMoveJump(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_LEFT_STOP);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightLeftStop"));
	k->getKnightMotion()->start();

}

void knight::rightMoveJump(void* obj)
{
	knight* k = (knight*)obj;

	k->setKnightDirection(KNIGHTDIRECTION_RIGHT_STOP);
	k->setKnightMotion(KEYANIMANAGER->findAnimation("knightRightStop"));
	k->getKnightMotion()->start();

}