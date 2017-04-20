#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init(void)
{


	return S_OK;
}

void imageManager::release(void)
{

}

//빈 비트맵 이미지
image* imageManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//리소스 이미지
image* imageManager::addImage(string strKey, const DWORD resID, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(resID, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//파일 이미지
image* imageManager::addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//파일 이미지
image* imageManager::addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}


//프레임 이미지 
image* imageManager::addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//이미지가 있으면 그걸 넘겨라
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- 알아서 형을 찾아서 넣어준다
	//pair<형1, 형2>(값1, 값2)  <- 형을 지정해주고 담는다
	//pair를 왜써요? 할수있는데 벡터나, 클래스등이 너무 많아 모호할때 씀
	_mImageList.insert(make_pair(strKey, img));

	return img;
}


//이미지 찾아오는 함수
image* imageManager::findImage(string strKey)
{
	//맵에서 해당 키를 찾아서 이터레이터에 대입한다
	mapImageIter key = _mImageList.find(strKey);

	//키값이 있으면
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}


//이미지 지움지움
BOOL imageManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//해당 이미지가 있으면
	if (key != _mImageList.end())
	{
		//찾아서 지워줌
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

//이미지 모조리 삭제
BOOL imageManager::deleteAll(void)
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	_mImageList.clear();

	return TRUE;
}


void imageManager::render(string strKey, HDC hdc)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	image* img = findImage(strKey);

	if (img) img->alphaRender(hdc, alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = findImage(strKey);

	if (img) img->alphaRender(hdc, destX, destY, alpha);
}

void imageManager::alphaRender(string strkey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	image* img = findImage(strkey);

	if (img) img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
}