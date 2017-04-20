#include "stdafx.h"
#include "effect.h"
#include "animation.h"

effect::effect()
	:	_effectImage(NULL),
		_effectAnimation(NULL),
		_isRunning(false),
		_x(0), 
		_y(0)
{
}


effect::~effect()
{

}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	//이펙트 이미지가 없다면 실행하지 말라
	if (!effectImage) return E_FAIL;

	_isRunning = false;
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	//이펙트애니메이션이 없으면 새로 생성한다
	if (!_effectAnimation) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();


	return S_OK;
}
void effect::release(void)
{
	_effectImage = NULL;
	SAFE_DELETE(_effectAnimation);

}

void effect::update(void)
{
	//애니메이션이 활성화 되어있지 않다면 돌아가시오
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	if (!_effectAnimation->isPlay()) killEffect();
}

void effect::render(void)
{
	if (!_isRunning) return;

	_effectImage->aniRender(getMemDC(), _x, _y, _effectAnimation);
}


void effect::startEffect(int x, int y)
{
	//이미지나 애니메이션이나 둘중 하나라도 셋팅이 안되어있다면
	if (!_effectImage || !_effectAnimation) return;

	//레프트 탑 좌표를 센터좌표로
	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;
	_effectAnimation->start();
}

void effect::killEffect(void)
{
	_isRunning = false;
}

