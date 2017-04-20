#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"


spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{

}

HRESULT spaceShip::init()
{
	
	_ship = IMAGEMANAGER->addImage("ship", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2 - _ship->getWidth() / 2);
	_ship->setY(WINSIZEY / 2 + _ship->getHeight() / 2 + 100);

	_missile = new missile;
	_missile->init(30, 400);

	_mdMissile = new modenMissile;
	_mdMissile->init(30, 500);

	_currentHP = _maxHP = 100.0f;

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 10, 53, 5);
	_hpBar->setGauge(_currentHP, _maxHP);

	_alphaValue = 50;

	return S_OK;
}
void spaceShip::release()
{

}
void spaceShip::update() 
{

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getX() + _ship->getWidth() / 2, _ship->getY() - 30);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_mdMissile->fire(_ship->getX() + _ship->getWidth() / 2, _ship->getY() - 30);
	}


	_missile->update();
	_mdMissile->update();

	collision();

	//업데이트에 넣어줘야 위에 HP막대기가 따라다닌다
	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 10);

	_hpBar->setGauge(_currentHP, _maxHP);

	_hpBar->update();

	//저장 먼저
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("blueSaveTest.txt", vStr);
	}

	//로드 
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("blueSaveTest.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_ship->setX(atoi(vStr[2].c_str()));
		_ship->setY(atoi(vStr[3].c_str()));
	}


	_alphaValue--;

	if (_alphaValue <= 0) _alphaValue = 255;


}
void spaceShip::render() 
{
	_ship->alphaRender(getMemDC(), _alphaValue);

	_missile->render();
	_mdMissile->render();

	_hpBar->render();
}

//2번!
void spaceShip::collision()
{
	for (int i = 0; i < _mdMissile->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;

			if (IntersectRect(&temp, &_mdMissile->getVBullet()[i].rc,
				&_em->getVMinion()[j]->getRect()))
			{
				_mdMissile->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}


void spaceShip::removeMissile(int arrNum)
{
	_mdMissile->removeMissile(arrNum);
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}