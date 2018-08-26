// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "stdafx.h"

TestApp::TestApp() : Parent(30, 18)
{
	/*mDirection = true;
	mObj1XOld = mObj1X = 10;
	mObj1YOld = mObj1Y = 10;
	mObj2X = 10;
	mObj2Y = 12;*/
	SetBorders();
}

void TestApp::KeyPressed(int btnCode)
{
	GetShape()->Print(*this, ' ');

	if (btnCode == 115) //s
	{
		if (Can_Move(*GetShape(), 4)) {
			
			GetShape()->Move(4);

		}
	}
	else if (btnCode == 97) //a
	{
		if (Can_Move(*GetShape(), 3)) {
			GetShape()->Move(3);
		}
	}
	else if (btnCode == 100) //d
	{
		if (Can_Move(*GetShape(), 2)) {
			GetShape()->Move(2);
		}
	}
	else if (btnCode == 32) //space
	{
		GetShape()->Rotate_With_Checks(*this);
	}
	GetShape()->Print(*this, '#');

}

//void TestApp::UpdateF(float deltaTime)
//{
//	//SetChar(mObj1XOld, mObj1YOld, L' ');
//	//SetChar(mObj1X, mObj1Y, L' ');
//
//	//mObj1XOld = mObj1X;
//	//mObj1YOld = mObj1Y;
//
//	////-----------------------------
//
//	////SetChar(mObj2X, mObj2Y, L' ');
//	//if (mDirection)
//	//{
//	//	mObj2X++;
//	//	if (mObj2X == 40)
//	//		mDirection = false;
//	//}
//	//else
//	//{
//	//	mObj2X--;
//	//	if (mObj2X == 10)
//	//		mDirection = true;
//	//}
//	//SetChar(mObj2X, mObj2Y, L'F');
//}

