//헤더파일
#include "stdafx.h"
#include "mainGame.h"

//전역변수
HINSTANCE _hInstance;
HWND _hWnd;

//마우스 포인트 값
POINT _ptMouse;

mainGame _mg;

LPTSTR _lpszClass = TEXT("BLUE_API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{

	MSG message;		//윈도우 메시지 받을 구조체
	WNDCLASS wndClass;	//윈도우 정보를 담은 구조체

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;											//클래스 여분 메모리
	wndClass.cbWndExtra = 0;											//윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//윈도우 백그라운드 색상
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서 모양
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//윈도우 아이콘 모양
	wndClass.hInstance = hInstance;										//윈도우 인스턴스
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//프로시져
	wndClass.lpszClassName = WINNAME;								//클래스 이름
	wndClass.lpszMenuName = NULL;										//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//윈도우 스타일

																		//윈도우 정보를 등록
	RegisterClass(&wndClass);

	//윈도우 창 생성
	_hWnd = CreateWindow(
		WINNAME,				//윈도우 클래스 이름
		WINNAME,				//윈도우 타이틀 바에 이름
		WS_OVERLAPPEDWINDOW,	//윈도우 스타일
		WINSTARTX,				//윈도우 창 시작 X좌표
		WINSTARTY,				//윈도우 창 시작 Y좌표
		WINSIZEX,				//윈도우 창 가로크기
		WINSIZEY,				//윈도우 창 세로크기
		NULL,					//부모 윈도우 유무
		(HMENU)NULL,			//메뉴 핸들
		hInstance,				//인스턴스 윈도우 지정
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);


	//화면에 윈도우 창을 보여준다
	ShowWindow(_hWnd, cmdShow);

	//메인게임 초기화 실패면
	if (FAILED(_mg.init()))
	{
		return 0; //꺼버렷!
	}

	//게임용 나중을 위해 봉인해 둘 것.
	while (true)
	{
		if (PeekMessage( &message, NULL, 0, 0, PM_REMOVE ))
		{
			if (message.message == WM_QUIT)break;
			TranslateMessage( &message );
			DispatchMessage( &message );
		}
		else
		{
			//             요고는 자기가 120하고싶으면 바꿩
			TIMEMANAGER->update(60.0f);
			_mg.update();
			_mg.render();
		}
	}
	
	

	/*
	//메시지 처리 루프
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//키보드 입력 메시지 처리 담당
		DispatchMessage(&message);//실제로 윈도우로 메시지 처리
	}
	*/

	//메시지 루프 다돌았으면
	_mg.release(); //메인게임 해제
				   //윈도우 등록된것 해제
	UnregisterClass(WINNAME, hInstance);

	return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _mg.MainProc(hWnd, iMessage, wParam, lParam);
}

//클라이언트 영역 재조정 함수
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//비작업 영역을 제외한 작업 영역안의 크기만 맞춰줌.
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}