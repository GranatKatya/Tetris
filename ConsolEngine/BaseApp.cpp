// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#define MY_PERFORMENCE_COUNTER
#include "stdafx.h"

class Shape;

BaseApp::BaseApp(int xSize, int ySize) : X_SIZE(xSize), Y_SIZE(ySize)
{
	SMALL_RECT windowSize = {0, 0, X_SIZE, Y_SIZE};
	COORD windowBufSize = {X_SIZE+1, Y_SIZE+1};

	mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

	if(!SetConsoleScreenBufferSize(mConsole,  windowBufSize))
	{
		cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
	}
	if(!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
	{
		cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
	}

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;// invisible
	cursorInfo.dwSize = 1;// decrease size 
	SetConsoleCursorInfo(mConsole, &cursorInfo);


	mChiBuffer = (CHAR_INFO*)malloc((X_SIZE+1)*(Y_SIZE+1)*sizeof(CHAR_INFO));

	mDwBufferSize.X = X_SIZE + 1;
	mDwBufferSize.Y = Y_SIZE + 1;		// размер буфера данных

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;				// координаты €чейки

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = X_SIZE + 1;
	mLpWriteRegion.Bottom = Y_SIZE + 1;	// пр€моугольник дл€ чтени€


	for (int x=0; x<X_SIZE+1; x++)
	{
		for (int y=0; y<Y_SIZE+1; y++)
		{
			SetChar(x, y, L' ');
		}
	}
}

BaseApp::~BaseApp()
{
	free(mChiBuffer);
}

void BaseApp::SetChar(int x, int y, wchar_t c)
{
	mChiBuffer[x + (X_SIZE+1)*y].Char.UnicodeChar = c;
	mChiBuffer[x + (X_SIZE+1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

}

wchar_t BaseApp::GetChar(int x, int y)
{
	return mChiBuffer[x + (X_SIZE+1)*y].Char.AsciiChar;
}

void BaseApp::Render()
{
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion)) 
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
	}
}

void BaseApp::Run()
{
	CStopwatch timer;
	int sum = 0;
	int counter = 0;

	int deltaTime = 0;


	shape.Create_Shape(shapetemplate);
	while (1)
	{

		timer.Start();
		if (kbhit())
		{
			KeyPressed(getch());
			if (!FlushConsoleInputBuffer(mConsoleIn)) // чистим буфер kbhit
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}

		//UpdateF((float)deltaTime / 1000.0f);
		Render();
		Sleep(400);

		while (1)
		{
			deltaTime = timer.Now();
			if (deltaTime > 20)
				break;
		}

		sum += deltaTime;
		counter++;
		if (sum >= 1000)
		{
			TCHAR  szbuff[255];
			StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
			SetConsoleTitle(szbuff);

			counter = 0;
			sum = 0;
		}

		UpdateF();
		/*if (!Can_Move(shape, 4)) {
			shape.Create_Shape(shapetemplate);
		}*/

	}

}




bool BaseApp::Check_Overlap(Shape &shape) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (shape.GetY() + i >= 0 && shape.GetX() + j >= 0 && shape.GetY() + i <= 15 && shape.GetX() + j <= 14) {
				if (GetChar(shape.GetX() + j, shape.GetY() + i) == '*' && shape.GetArrayElement(j,i) == '#') {
					return true;
				}
			}
		}
	}
	return false;
}


bool BaseApp::Check_In_Borders(Shape &shape) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (shape.GetArrayElement(i,j) == '#') {
				if ((j + shape.GetY()) > 15) {
					return false;
				}
				if ((i + shape.GetX()) < 3) {
					return false;
				}
				if ((i + shape.GetX()) > 16) {
					return false;
				}
			}
		}
	}
	return true;
}

bool BaseApp::Can_Move(Shape shape, int direction) {
	Shape temp_shape = shape;
	//Move_Shape(temp_shape, direction);
	temp_shape.Move(direction);
	if (Check_Overlap(temp_shape)) {
		return false;
	}

	if (!Check_In_Borders(temp_shape)) {
		return false;
	}
	return true;
}


 void BaseApp::UpdateF() {
	if (Can_Move(shape, 4)) {
		shape.Print(*this, ' ');
		shape.Move(4);
		shape.Print(*this, '#');
	}
	else {
		Fix_Shape(); // add shape to our building
		Check_Line();
		GetShape()->SetX(7);
		GetShape()->SetY(-2);
		GetShape()->Create_Shape(shapetemplate);
	}
}


void BaseApp::Remove_Line(int line) {

	for (int i = 0; i < 15; i++) {
		SetChar(i, line, ' ');
	}
	Render();
	Sleep(30);

	for (int i = line - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			SetChar(j, i + 1, GetChar(j, i));
		}
	}

	Render();
}


void BaseApp::Check_Line() {
	int multiplicator = 1;
	for (int i = 0; i < 15; i++) {
		bool line_completed = true;
		for (int j = 0; j < 15; j++) {
			if (GetChar(j, i) == ' ') {
				line_completed = false;
			}
		}
		if (line_completed == true) {
			Remove_Line(i);
			/*score += 10 * multiplicator;
			multiplicator++;
			Print_Score();*/
		}
	}

}

void BaseApp::Fix_Shape() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (shape.GetArrayElement(i, j) == '#') {
				if (shape.GetY() + i >= 0 && shape.GetY() + i <= 15 && shape.GetX() + j >= 0 && shape.GetX() + j <= 15) {
					//SetChar((shape.GetX() + j), (shape.GetY() + i), '*');
					GetShape()->Print(*this, '*');
				}
			}
		}
	}
}

