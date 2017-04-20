#pragma once
#include "gameNode.h"
<<<<<<< HEAD
#include "PlayerManager.h"
=======
#include "zombieManager.h"

>>>>>>> 45ae986ace1eec4cd663aa0e67944bcc9733a9d1

class mainGame : public gameNode
{
private:
<<<<<<< HEAD
	PlayerManager* _pm;


=======

	zombieManager* _zm;
>>>>>>> 45ae986ace1eec4cd663aa0e67944bcc9733a9d1

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();




	mainGame();
	~mainGame();
};

