#include <windows.h>
#include <gl/gl.h>

#include "ShapeCreator.h"
#include <cmath>

const float defaultQuadStartX = 0.0f;
const float defaultQuadStartY = 0.0f;
const float defaultQuadWidth = 1.0f;
const float defaultQuadHeight = 1.0f;

const float defaultTriangleStartX = 0.0f;
const float defaultTriangleStartY = 0.0f;
const float defaultTriangleWidth = 1.0f;
const float defaultTriangleHeight = 1.0f;


ShapeCreator::ShapeCreator()
{
}

ShapeCreator::~ShapeCreator()
{
}

std::vector<POINTFLOAT> ShapeCreator::createBasicShape(const Shapes shape)
{
	switch (shape)
	{
	case Shapes::Quad:
	{
		return createQuad(defaultQuadStartX,
						  defaultQuadStartY,
						  defaultQuadWidth,
						  defaultQuadHeight);
	}
	case Shapes::Triangle:
	{
		return createTriangle(defaultTriangleStartX, 
							  defaultTriangleStartY, 
							  defaultTriangleWidth, 
							  defaultTriangleHeight);
	}
	case Shapes::Circle:
	{
		return createCircle(defaultTriangleStartX,
							  defaultTriangleStartY,
							  1,
							  10);
	}
	}

	return std::vector<POINTFLOAT>();
}

std::vector<POINTFLOAT> ShapeCreator::createQuad(const float startX,
												 const float startY, 
												 const float width, 
												 const float height)
{
	const float halfOfWidth = width * 0.5f;
	const float halfOfHeight = height * 0.5f;

	std::vector<POINTFLOAT> vertices = {
		{ startX - halfOfWidth,	startY + halfOfHeight }, // Top left
		{ startX + halfOfWidth, startY + halfOfHeight }, // Top right
		{ startX + halfOfWidth,	startY - halfOfHeight }, // Bottom right
		{ startX - halfOfWidth,	startY - halfOfHeight }  // Bottom left
	};

	return vertices;
}

std::vector<POINTFLOAT> ShapeCreator::createTriangle(const float startX,
													 const float startY, 
													 const float width, 
													 const float height)
{
	const float halfOfWidth = width * 0.5f;
	const float halfOfHeight = height * 0.5f;

	std::vector<POINTFLOAT> vertices = {
		{ startX,		        startY + halfOfHeight },
		{ startX - halfOfWidth, startY - halfOfHeight },
		{ startX + halfOfWidth, startY - halfOfHeight }
	};

	return vertices;
}

std::vector<POINTFLOAT> ShapeCreator::createCircle(const float startX,
												   const float startY,
												   const float radius,
												   const float steps)
{
	const float halfOfRadius = radius * 0.5f;
	const float angle = 3.14159265358979323846 * 2 / steps;
	std::vector<POINTFLOAT> vertices;
	vertices.reserve(sizeof(POINTFLOAT) * steps);

	vertices.push_back({ startX , startY });
	for (short i = 0; i <= steps; ++i)
	{
		vertices.push_back({ halfOfRadius * sin(angle*i),
						     halfOfRadius * cos(angle * i) });
	}

	return vertices;
}
