#pragma once
#include "gameNode.h"
#include "bullets.h"

class ship : public gameNode
{
protected:
	bullet* _bullet;

	image* _image;
	RECT _rc;
	float _x, _y;
	float _angle;
	float _speed;
	float _radius;

public:
	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void draw();
	virtual void keyControl();
	virtual void move();

	virtual void bulletFire(void);
	virtual void bulletMove(void);
	virtual void bulletDraw(void);

	virtual void focusDraw(void);
	virtual void defaultDraw(RECT rcFocus);

	image* getImage(void) { return _image; }
	RECT getRect(void) { return _rc; }

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }

	ship();
	virtual ~ship();
};

