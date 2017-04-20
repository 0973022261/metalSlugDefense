#pragma once
#include "gameNode.h"
#include "zombie.h"

class zombieManager : public gameNode
{
private:
	typedef vector<zombie*> vZombie;
	typedef vector<zombie*>::iterator viZombie;

private:
	vZombie _vZombie;
	viZombie _viZomibe;

public:
	HRESULT init();
	void release();
	void render();
	void update();

	vZombie getVZombie() { return _vZombie; }

	zombieManager();
	~zombieManager();
};

