#include "stdafx.h"
#include "keyAniManager.h"
#include "image.h"
#include "animation.h"

keyAniManager::keyAniManager()
{
}


keyAniManager::~keyAniManager()
{
}

HRESULT keyAniManager::init()
{

	return S_OK;
}

void keyAniManager::release()
{
	deleteAll();
}

void keyAniManager::update()
{
	iterAnimations iter = _mTotalAnimations.begin();

	for (iter; iter != _mTotalAnimations.end(); ++iter)
	{
		//맵의 세컨드 == 애니메이션 클라스 
		if (!iter->second->isPlay()) continue;
		//재생해라
		iter->second->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
	}
}

void keyAniManager::render()
{
	
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimations.insert(pair<string, animation*>(animationKeyName, ani));
}

void keyAniManager::start(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimations.find(animationKeyName);
	iter->second->start();
}

void keyAniManager::stop(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimations.find(animationKeyName);
	iter->second->stop();
}

void keyAniManager::pause(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimations.find(animationKeyName);
	iter->second->pause();
}

void keyAniManager::resume(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimations.find(animationKeyName);
	iter->second->resume();
}

animation* keyAniManager::findAnimation(string animationKeyName)
{
	iterAnimations iter = _mTotalAnimations.find(animationKeyName);

	if (iter != _mTotalAnimations.end())
	{
		return iter->second;
	}

	return NULL;
}

void keyAniManager::deleteAll()
{
	for (iterAnimations iter = _mTotalAnimations.begin(); iter != _mTotalAnimations.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mTotalAnimations.erase(iter);
		}
		else ++iter;

	}

	_mTotalAnimations.clear();
}