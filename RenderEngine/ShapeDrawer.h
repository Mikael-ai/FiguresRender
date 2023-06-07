#pragma once

#include "Shapes.h"
#include <vector>

class ShapeDrawer 
{
public:
	ShapeDrawer();
	~ShapeDrawer();
	
	/**
	*  Draw shape
	*  @param vertices - collection of points to draw
	*  @param scale - scale of a draw context
	*  @param rotation - rotation of a draw context
	*  @param hDC - device context handle
	*/
	static void drawShape(const std::vector<POINTFLOAT> &vertices,
						  const float scale,
						  const float rotation,
						  HDC *hDC);
};