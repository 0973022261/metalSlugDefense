#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "mainScene.h"
#include "stage1Scene.h"
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

<<<<<<< HEAD
	void addImage();


=======
>>>>>>> master/master
	mainGame();
	~mainGame();
};

