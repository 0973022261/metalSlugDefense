#pragma once
#include "gameNode.h"
#include "PlayerManager.h"

class mainGame : public gameNode
{
private:
	PlayerManager* _pm;



public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();




	mainGame();
	~mainGame();
};

