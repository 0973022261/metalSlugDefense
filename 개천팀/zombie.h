#pragma once
#include "gameNode.h"


struct ZOMBIE
{
	image* _zombieImage;
	RECT _rc;
	float _x, _y;
	float _speed;
	int _attackDamage;
	int _hp;

	ZOMBIE()
	{
		_zombieImage = NULL;
		_rc = RectMakeCenter(0, 0, 0, 0);
		_x = _y = 0;
		_speed = 0;
		_attackDamage = 0;
		_hp = 0;
	}
};
class zombie : public gameNode
{
private:
	ZOMBIE _zombie;

public:
	virtual HRESULT init(const char* imageName, float x, float y,float speed,int attackDamage, int hp);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();

	ZOMBIE getZombie() { return _zombie; }

	zombie();
	~zombie();
};

