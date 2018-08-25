#pragma once

#include "stdafx.h"

class BaseApp;
class Shape {

	wchar_t _array[4][4];
	int _x;
	int _y;
	int color[3];
public:

	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	wchar_t GetAArrayElement(int x, int y);
	void Rotate();
	void Rotate_With_Checks(BaseApp &app);
	void Move(int direction);
	void Print(BaseApp &app, wchar_t ch);


};
