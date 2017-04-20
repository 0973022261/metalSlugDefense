#pragma once
#include "gameNode.h"
#include "animation.h"

class camel : public gameNode
{
private:
	image* _camel;

	animation* _ani1;
	animation* _ani2;
	animation* _ani3;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	camel();
	~camel();
};

