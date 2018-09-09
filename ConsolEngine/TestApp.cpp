// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "stdafx.h"

TestApp::TestApp() : Parent(22, 18)
{
	

	SetBorders();
}

void TestApp::KeyPressed(int btnCode)
{
	GetShape()->Print(*this, ' ');

	if (btnCode == 224)
	{
		switch (btnCode)
		{

		case 80: // вниз
			if (Can_Move(*GetShape(), 4)) {

				GetShape()->Move(4);

			}
			break;
		case 77://вправо
			if (Can_Move(*GetShape(), 2)) {
				GetShape()->Move(2);
			}
			break;

		case 75:
			if (Can_Move(*GetShape(), 3)) {
				GetShape()->Move(3);
			}
			break;
		case 32: //space

			GetShape()->Rotate_With_Checks(*this);
			break;
		default:
			break;

		}
	}


	switch (btnCode)
	{

	case 80: // вниз
		if (Can_Move(*GetShape(), 4)) {

			GetShape()->Move(4);

		}
		break;
	case 77://вправо
		if (Can_Move(*GetShape(), 2)) {
			GetShape()->Move(2);
		}
		break;

	case 75:
		if (Can_Move(*GetShape(), 3)) {
			GetShape()->Move(3);
		}
		break;
	case 32: //space

		GetShape()->Rotate_With_Checks(*this);
		break;
	default:
		break;

	}



	GetShape()->Print(*this, '#');

}
