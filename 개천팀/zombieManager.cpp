#include "stdafx.h"
#include "zombieManager.h"


zombieManager::zombieManager()
{
}


zombieManager::~zombieManager()
{
}

HRESULT zombieManager::init()
{


	return S_OK;
}
void zombieManager::release()
{

}

void zombieManager::update()
{
	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->update();
	}
}

void zombieManager::render()
{
	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->update();
	}
}


void zombieManager::makeZombie(float x, float y, int type)
{
	switch (type)
	{
		//기본좀비
		case 0:
		{
			
			_zombie = new zombie1;
			_zombie->init("zombie1",x,y,5.0f,10.0f,100);
			_vZombie.push_back(_zombie);
			
		}
		break;
	}
}

void zombieManager::removeZombie(int num)
{
	SAFE_DELETE(_vZombie[num]);
	_vZombie.erase(_vZombie.begin() + num);
}