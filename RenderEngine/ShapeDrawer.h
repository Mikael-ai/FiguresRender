#pragma once

#include "Shapes.h"
#include <vector>

class ShapeDrawer {
public:
	ShapeDrawer();
	~ShapeDrawer();
	
	static void drawShape(const std::vector<POINTFLOAT> &vertices,
						  const float scale,
						  HDC *hDC);
};