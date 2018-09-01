#include "stdafx.h"
#ifdef MY_PERFORMENCE_COUNTER

CStopwatch::CStopwatch()
{
	QueryPerformanceFrequency(&m_liPerfFreq);//получает частоту производительности   с запуска проги MY_PERFORMENCE_COUNTER в секкунду
	Start();
}

void CStopwatch::Start()
{
	QueryPerformanceCounter(&m_liPerfStart);//сколько раз вызывается с запуска проги
}

int CStopwatch::Now()
{
	// возвращает число миллисекунд после вызова Start
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
}

int CStopwatch::Time()
{
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return ((liPerfNow.QuadPart * 1000) / m_liPerfFreq.QuadPart);
}

#endif