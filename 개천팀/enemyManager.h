#pragma once
#include "gameNode.h"
#include "minion.h"
#include <vector>
#include "bullets.h"
//��ó���� �ܰ迡�� ������ �����ϱ� ����
//�ٵ� ������ ���漱�� ��û ���̾�
//��� �˴� ���漱���Ѵٰ� ���� ������ �ƴ������� ���ϴ�
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

