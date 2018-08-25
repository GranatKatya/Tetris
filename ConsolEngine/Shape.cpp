#include "stdafx.h"

int Shape::GetX() { return _x; }
int Shape::GetY() { return _y; }
void Shape::SetX(int x) { _x = x; }
void Shape::SetY(int y) { _y = y; }
wchar_t Shape::GetAArrayElement(int x, int y) { return _array[x][y]; }
//	void  Shape::SetArray(COORD array) {}

void Shape::Rotate() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_array[i][j] = _array[j][3 - i];
		}
	}
}

void Shape::Rotate_With_Checks(BaseApp &app) {//��������� ������

	Shape temp_shape = *this;
	temp_shape.Rotate();

	if (app.Check_Overlap(temp_shape)) {//������������
		return;
	}
	if (_y > 15) {// y
		return;
	}
	if (!app.Check_In_Borders(temp_shape)) {// ������� x
		int direction;
		if (_x < 0) {
			direction = 2;
		}
		else {
			direction = 3;
		}
		if (app.Can_Move(temp_shape, direction)) {
			Print(app, ' ');
			Rotate();
			Move(direction);
			Print(app, '#');
		}
		else {
			temp_shape.Move(direction);
			if (app.Can_Move(temp_shape, direction)) {
				Print(app, ' ');
				Rotate();
				Move(direction);
				Print(app, '#');
			}
		}

	}
	else {
		Print(app, ' ');
		Rotate();
		Print(app, '#');
	}
}

void Shape::Move(int direction) {
	switch (direction) {
	case 2: // move right
		_x += 1;
		break;
	case 3: // move left
		_x -= 1;
		break;
	case 4: // move down
		_y += 1;
		break;
	}
}

void Shape::Print(BaseApp &app, wchar_t ch) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (_array[i][j] == '#') {
				if (_y + i >= 0) {
					app.SetChar(_x + j, _y + i, ch);
				}
			}
		}
	}
}