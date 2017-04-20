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

	zombie* _zombie;
public:
	HRESULT init();
	void release();
	void render();
	void update();

	void makeZombie(float x, float y, int type);
	void removeZombie(int num);

	vZombie getVZombie() { return _vZombie; }

	zombieManager();
	~zombieManager();
};

