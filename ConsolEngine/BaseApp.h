// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.



#include "stdafx.h"

class Shape;


class BaseApp
{
private:
	HANDLE mConsole;
	HANDLE mConsoleIn;

	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;

	Shape shape;
	ShapeTemplates shapetemplate;

	void Render();

public:
	//������� ������� ������ �� ����������� � ��������� � ��������
	const int X_SIZE;
	const int Y_SIZE;

	//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
	BaseApp(int xSize=15, int ySize=15);
	virtual ~BaseApp();

	//��������� ������� ����
	void Run();

	//����� ��������� x,y-������ ������ ������������ ��������, ��� ������� ���
	void SetChar(int x, int y, wchar_t c);
	wchar_t GetChar(int x, int y);

	/*��� ������� ���������� ������ ������� ��������, � ����� ��������������, � ���������� ������.
	� �� �������� deltaTime - ������� �� ������� ����� ���������� ��������� � ����, � ��������*/
	//virtual void UpdateF (float deltaTime){}
	/*��� ������� ���������� ��� ������� ������� �� ����������, � �� �������� ��� ������� - btnCode.
	���� ������������ ������� ��� �������������� �������, �� ������ ����� ��� ��� �����, �������� 224, � ��������� �� ��� - 
	����� ��� ��������������� ��� ����� �������, ��� ����� ��������, ������ ����� getch().
	����� KeyPressed ��� �� ����� �������������� � ����������*/
	virtual void KeyPressed (int btnCode){}
	
	bool Check_Overlap(Shape &shape);
	bool Check_In_Borders(Shape &shape);
	bool Can_Move(Shape shape, int direction);

	virtual void UpdateF();
	void Remove_Line(int line);
	void Check_Line();
	void Fix_Shape();

	Shape* GetShape() {
		return &shape;
	}
};