#pragma once

#include "Shapes.h"
#include <vector>


extern const float defaultQuadStartX;
extern const float defaultQuadStartY;
extern const float defaultQuadWidth;
extern const float defaultQuadHeight;

extern const float defaultTriangleStartX;
extern const float defaultTriangleStartY;
extern const float defaultTriangleWidth;
extern const float defaultTriangleHeight;


class ShapeCreator {
public:
	ShapeCreator();
	~ShapeCreator();

	static std::vector<POINTFLOAT> createBasicShape(const Shapes shape);

	static std::vector<POINTFLOAT> createQuad(const float startX,
											  const float startY,
											  const float width,
											  const float height);

	static std::vector<POINTFLOAT> createTriangle(const float startX,
												  const float startY,
												  const float width,
												  const float height);

	static std::vector<POINTFLOAT> createCircle(const float startX,
												const float startY,
												const float radius,
												const float steps);
};
