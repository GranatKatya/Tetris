// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#pragma once
#include "stdafx.h"

class CStopwatch
{
public:
	CStopwatch();
	void Start();
	int Now();
	int Time();
private:
	LARGE_INTEGER m_liPerfFreq;
	LARGE_INTEGER m_liPerfStart;
};

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
