#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	//          first   second
	typedef map<string, image*> mapImageList;
	typedef map<string, image*>::iterator mapImageIter;

private:
	mapImageList _mImageList;
	

public:
	HRESULT init(void);
	void release(void);

	//빈 비트맵 이미지
	image* addImage(string strKey, int width, int height);
	//리소스 이미지
	image* addImage(string strKey, const DWORD resID, int width, int height, bool trans, COLORREF transColor);
	//파일 이미지
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	//파일 이미지
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor);

	//프레임 이미지 
	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	//이미지 찾아오는 함수
	image* findImage(string strKey);

	//이미지 지움지움
	BOOL deleteImage(string strKey);
	//이미지 모조리 삭제
	BOOL deleteAll(void);

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//frameRender, loopRender 는 여러분이 추가해봐밥
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strkey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);



	imageManager();
	~imageManager();
};

