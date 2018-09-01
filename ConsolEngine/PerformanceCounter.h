// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#pragma once
#include "stdafx.h"


#define MY_PERFORMENCE_COUNTER

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


