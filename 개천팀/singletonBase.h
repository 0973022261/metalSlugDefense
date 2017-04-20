#pragma once

template <typename T>
class singletonBase
{
protected:
	//½Ì±ÛÅæ ÀÎ½ºÅÏ½º ¼±¾ð
	static T* singleton;

	singletonBase(void) {};
	~singletonBase(void) {};
public:
	static T* getSingleton(void);
	void releaseSingleton(void);

};


//½Ì±ÛÅæ ÃÊ±âÈ­
template <typename T>
T* singletonBase<T>::singleton = 0;

//½Ì±ÛÅæ °ª °¡Á®¿Â´Ù
template <typename T>
T* singletonBase<T>::getSingleton(void)
{
	if (!singleton) singleton = new T;

	return singleton;
}

template <typename T>
void singletonBase<T>::releaseSingleton(void)
{
	if (singleton)
	{
		delete singleton;

		singleton = 0;
	}
}