// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include "stdafx.h"

class TestApp : public BaseApp
{
	typedef BaseApp Parent;

	private:
		

		
	public:
		TestApp();
		virtual void KeyPressed(int btnCode);
	//	virtual void UpdateF();


		//initialized field 
		void SetBorders() {
			for (int i = 3; i < 17; i++) {

				SetChar(i, 1, L'_');
				SetChar(i, 16, L'T');
			}

			for (int j = 2; j < 17; j++) {

				SetChar(2, j, L'|');
				SetChar(17, j, L'|');
			}
		}


		
};
