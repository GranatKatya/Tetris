// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.



//#include "stdafx.h"

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
	Shape nextShape;
	ShapeTemplates shapetemplate;

	int mscore = 0;

	void Render();

public:
	//размеры области вывода по горизонтали и вертикали в символах
	const int X_SIZE;
	const int Y_SIZE;

	//аргументами €вл€ютс€ размеры области вывода по горизонтали и вертикали в символах
	BaseApp(int xSize=15, int ySize=15);
	virtual ~BaseApp();

	//запускает игровой цикл
	void Run();

	//можно заполнить x,y-символ экрана определенным символом, или считать его
	void SetChar(int x, int y, wchar_t c);
	wchar_t GetChar(int x, int y);

	/*эта функци€ вызываетс€ каждую игровую итерацию, еЄ можно переопределить, в наследнике класса.
	в неЄ приходит deltaTime - разница во времени между предыдущей итерацией и этой, в секундах*/
	//virtual void UpdateF (float deltaTime){}
	/*эта функци€ вызываетс€ при нажатии клавиши на клавиатуре, в неЄ приходит код клавиши - btnCode.
	если использовать стрелки или функциональные клавиши, то придет общее дл€ них число, например 224, а следующее за ним - 
	будет уже непосредственно код самой клавиши, его можно получить, вызвав метод getch().
	ћетод KeyPressed так же можно переопределить в наследнике*/
	virtual void KeyPressed (int btnCode){}
	
	bool Check_Overlap(Shape &shape);
	bool Check_In_Borders(Shape &shape);
	bool Can_Move(Shape shape, int direction);

	virtual void UpdateF();
	void Remove_Line(int line);
	void Check_Line();
	void Fix_Shape();
	void SetShape(Shape shape);
	void Check_Lose() {
		for (int i = 3; i < 17; i++) {
			if (GetChar(i, 2) != ' ') { exit(0); }
		}
	}

	Shape* GetShape() {
		return &shape;
	}
	Shape* GetNextShape() {
		return &nextShape;
	}

	void PrintScore() {
		int score = mscore;
		int y;
		char yc[1];
		wchar_t yw[1];
		for (int i = 0; score != 0; i++) {
			y = score % 10;
			yc[0] = (char)(y + '0');
			mbstowcs(yw, yc, 1);
			SetChar(26-i, 14,*yw );
			score /= 10;
		}
		
	}

};