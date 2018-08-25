// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include "stdafx.h"

class TestApp : public BaseApp
{
	typedef BaseApp Parent;

	private:
		int mObj1XOld;
		int mObj1YOld;
		int mObj1X;
		int mObj1Y;

		int mObj2X;
		int mObj2Y;

		bool mDirection;


	

	public:
		TestApp();
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);


		//initialized field 
		void SetBorders() {
			for (int i = 3; i < 17; i++) {

				SetChar(i, 1, L'_');
				SetChar(i, 16, L'_');
			}

			for (int j = 2; j < 17; j++) {
				SetChar(2, j, L'|');
				SetChar(17, j, L'|');
			}
		}


		
};
