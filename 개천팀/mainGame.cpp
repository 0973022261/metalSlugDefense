#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//생성자 소멸자 빠이빠이
////////////////////////////////////

//초기화 해주는 함수
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	return S_OK;
}

//메모리 해제함수
void mainGame::release(void)
{
	gameNode::release();

}

//연산 하는 곳
void mainGame::update(void)
{
	gameNode::update();
	

	TIMEMANAGER->getElapsedTime();
		
}

//그려주는 곳
void mainGame::render()
{
	//흰색 도화지 한장이 필요함
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	TIMEMANAGER->render(getMemDC());

	TextOut(getMemDC(),WINSIZEX/2,WINSIZEY/2,"나는 개천에서 용났다 팀이야",strlen("나는 개천에서 용났다 팀이야"));

	//백버퍼에 옮겨 그려줄 애 건들지마라 얘는
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
