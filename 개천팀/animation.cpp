#include "stdafx.h"
#include "animation.h"


animation::animation()
	: _frameNum(0),
	_frameWidth(0),
	_frameHeight(0),
	_loop(FALSE),
	_frameUpdateSec(0),
	_elapsedSec(0),
	_nowPlayIdx(0),
	_play(FALSE)
{
}


animation::~animation()
{

}

//                        800           200           50          50
HRESULT animation::init(int totalW, int totalH, int frameW, int frameH)
{
	//가로 프레임 갯수
	_frameWidth = frameW;
	int _frameNumWidth = totalW / _frameWidth;

	//세로 프레임 갯수
	_frameHeight = frameH;
	int _frameNumHeight = totalH / _frameHeight;

	//총 프레임 갯수
	_frameNum = _frameNumWidth * _frameNumHeight;

	//해당 프레임 위치 셋팅완료
	for (int i = 0; i < _frameNumHeight; i++)
	{
		for (int j = 0; j < _frameNumWidth; j++)
		{
			POINT framePos;

			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			_frameList.push_back(framePos);
		}
	}

	//디폴트로 셋팅
	setDefPlayFrame();


	return S_OK;
}

void animation::release()
{

}

//디폴트 애니메이션
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	//루프 여부 대입받아온다
	_loop = loop;
	//플레이 리스트 클리어
	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	//루프 여부 대입받아온다
	_loop = loop;
	//플레이 리스트 클리어
	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	//루프 여부 대입받아온다
	_loop = loop;
	//플레이 리스트 클리어
	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//0 1 2 3 4 5 4 3 2 1 0
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

//배열 애니메이션
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}


//구간재생 애니메이션
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	//루프 여부 대입
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//시작과 끝이 같다? -> 1장
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else //리버스가 아니면
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}			
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}

}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	//루프 여부 대입
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//시작과 끝이 같다? -> 1장
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else //리버스가 아니면
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	//루프 여부 대입
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//시작과 끝이 같다? -> 1장
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else //리버스가 아니면
		{
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; i++)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}


void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}


void animation::frameUpdate(float elapsedTime)
{
	if (_play)
	{
		_elapsedSec += elapsedTime;

		//프레임 업데이트 할 시간이 되었다면
		if (_elapsedSec >= _frameUpdateSec)
		{
			//시간 초기화
			_elapsedSec -= _frameUpdateSec;
			//현재 재생중인 인덱스 -> 재생시켜준다
			_nowPlayIdx++;

			if (_nowPlayIdx == _playList.size())
			{
				if (_loop)
				{
					_nowPlayIdx = 0;
				}
				else
				{
					if (_obj == NULL)
					{
						if (_callbackFunction != NULL) _callbackFunction();
					}
					else
					{
						_callbackFunctionParameter(_obj);
					}

					_nowPlayIdx--;
					_play = FALSE;
				}
			}
		}

	}
}


void animation::start(void)
{
	_play = TRUE;
	_nowPlayIdx = 0;
}

void animation::stop(void)
{
	_play = FALSE;
	_nowPlayIdx = 0;
}

void animation::pause(void)
{
	_play = FALSE;
}

void animation::resume(void)
{
	_play = TRUE;
}
