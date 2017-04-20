#pragma once
#include "gameNode.h"
#include "minion.h"
#include <vector>
#include "bullets.h"
//전처리기 단계에서 꼬임을 방지하기 위해
//근데 실제로 전방선언 엄청 많이씀
//사실 죄다 전방선언한다고 봐도 과언이 아닐정도로 씁니다
class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;

	spaceShip* _spaceShip;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(void);
	void minionBulletFire(void);

	void removeMinion(int arrNum);

	void collision();

	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _spaceShip = ship; }


	vector<enemy*> getVMinion(void) { return _vMinion; }
	vector<enemy*>::iterator getVIMinion(void) { return _viMinion; }



	enemyManager();
	~enemyManager();
};

