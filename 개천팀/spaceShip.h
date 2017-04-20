#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//전방선언 -> 컴파일러한테 쫄지말고 일단 가봐
//상호참조를 위한 전방선언
//전처리기 단계에서 엉키는 것을 방지
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	modenMissile* _mdMissile;
	
	enemyManager* _em;

	progressBar* _hpBar;
	float _maxHP, _currentHP;

	int _alphaValue;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//충돌처리 해줄 함쑤
	void collision();

	//미사일 제거 할 함수
	void removeMissile(int arrNum);

	void hitDamage(float damage);

	//나중에 쉽 이미지 정보 불러올 접근자
	image* getShipImage() { return _ship; }

	modenMissile* getModenMissile() { return _mdMissile; }

	//나중에 메모리 주소값을 찾아주기 위한 함수
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	spaceShip();
	~spaceShip();
};

