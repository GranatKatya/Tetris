#pragma once

#include "stdafx.h"

class ShapeTemplates {
	wchar_t _shape_templates[7][4][4] = {
		{ { ' ' ,' ' ,' ' ,' ' },
	{ ' ','#','#',' ' },
	{ ' ','#','#',' ' },
	{ ' ' ,' ' ,' ' ,' ' } },//square



	{ { ' ', '#' ,' ' ,' ' },
	{ ' ' ,'#' ,' ' ,' ' },
	{ ' ' ,'#' ,' ' ,' ' },
	{ ' ' ,'#' ,' ' ,' ' } },//stick

	{ { ' ' ,' ' ,' ' ,' ' },
	{ '#' ,'#' ,'#' ,' ' },
	{ ' ' ,' ' ,'#' ,' ' },  //  1
	{ ' ' ,' ' ,' ' ,' ' } },//111

	{ { ' ' ,' ' ,' ' ,' ' },
	{ ' ' ,'#' ,' ' ,' ' },
	{ '#' ,'#' ,'#' ,' ' },
	{ ' ' ,' ' ,' ' ,' ' } },//

	{ { ' ' ,' ' ,' ' ,' ' },
	{ ' ' ,' ' ,'#' ,' ' },
	{ '#' ,'#' ,'#' ,' ' },
	{ ' ' ,' ' ,' ' ,' ' } },//


	{ { ' ' ,' ' ,' ' ,' ' },
	{ '#' ,'#' ,' ' ,' ' },
	{ ' ' ,'#' ,'#' ,' ' },
	{ ' ' ,' ' ,' ' ,' ' } },//

	{ { ' ' ,' ' ,' ' ,' ' },
	{ ' ' ,' ' ,'#' ,'#' },
	{ ' ' ,'#' ,'#' ,' ' },
	{ ' ' ,' ' ,' ' ,' ' } }//
	};

public:
	wchar_t* GetTemplate(int index) {
		return *_shape_templates[index];
	}
	wchar_t GetChar(int x, int y,int z) { return _shape_templates[x][y][z]; }
};