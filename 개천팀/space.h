#pragma once
#include "gameNode.h"
#include "ship.h"

enum DIRECTION
{
	DIRECTION_LEFT_TOP,			//0
	DIRECTION_MIDDLE_TOP,		//1
	DIRECTION_RIGHT_TOP,		//2
	DIRECTION_LEFT_MIDDLE,		//3
	DIRECTION_MIDDLE_MIDDLE,	//4
	DIRECTION_RIGHT_MIDDLE,		//5
	DIRECTION_LEFT_BOTTOM,		//6
	DIRECTION_MIDDLE_BOTTOM,	//7
	DIRECTION_RIGHT_BOTTOM		//8
};

class space : public gameNode
{
private:
	image* _background;
	int _mapSizeWidth;
	int _mapSizeHeight;

	ship* _ship;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	DIRECTION getDirection(int x, int y);

	void setShip(ship* obj) { _ship = obj; }

	space();
	~space();
};

