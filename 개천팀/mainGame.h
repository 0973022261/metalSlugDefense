#pragma once
#include "gameNode.h"
#include "zombieManager.h"


class mainGame : public gameNode
{
private:

	zombieManager* _zm;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();




	mainGame();
	~mainGame();
};

