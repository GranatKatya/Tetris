#include "stdafx.h"
#ifdef MY_PERFORMENCE_COUNTER

CStopwatch::CStopwatch()
{
	QueryPerformanceFrequency(&m_liPerfFreq);//�������� ������� ������������������   � ������� ����� MY_PERFORMENCE_COUNTER � ��������
	Start();
}

void CStopwatch::Start()
{
	QueryPerformanceCounter(&m_liPerfStart);//������� ��� ���������� � ������� �����
}

int CStopwatch::Now()
{
	// ���������� ����� ����������� ����� ������ Start
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