#pragma once
#include "gameNode.h"
#include "PlayerManager.h"
#include "zombieManager.h"

class mainGame : public gameNode
{
private:
	PlayerManager* _pm;
	zombieManager* _zm;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

