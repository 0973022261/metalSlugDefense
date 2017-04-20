#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}

HRESULT enemyManager::init(void)
{
	_bullet = new bullet;
	_bullet->init("bullet", 20, 700);



	return S_OK;
}

void enemyManager::release(void)
{

}

void enemyManager::update(void)	
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	_bullet->update();

	collision();

	minionBulletFire();
}

void enemyManager::render(void)	
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}


void enemyManager::setMinion(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("ufo", PointMake(100 + j * 80, 80 + i * 100));
			_vMinion.push_back(ufo);
		}
	}
}

void enemyManager::minionBulletFire(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			//RECT rc = (*_viMinion)->getRect();
			//_bullet->fire(rc.left + (rc.right - rc.left) / 2,
			//	rc.bottom + (rc.top - rc.bottom) / 2 + 30,
			//	-(PI / 2), 6.0f);

			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.top - rc.bottom) / 2 + 30,
				getAngle(rc.left + (rc.right - rc.left) / 2,
				rc.bottom,
				_spaceShip->getShipImage()->getX() + 
				_spaceShip->getShipImage()->getWidth() / 2,
				_spaceShip->getShipImage()->getY()), 6.0f);
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT rc;
		if (IntersectRect(&rc, &_bullet->getVBullet()[i].rc,
			&RectMake(_spaceShip->getShipImage()->getX(),
			_spaceShip->getShipImage()->getY(),
			_spaceShip->getShipImage()->getWidth(),
			_spaceShip->getShipImage()->getHeight())))
		{
			_spaceShip->hitDamage(10.0f);
			_bullet->removeBullet(i);
			break;
		}
	}
}