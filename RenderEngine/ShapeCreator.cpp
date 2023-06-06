#include <windows.h>
#include <gl/gl.h>

#include "ShapeCreator.h"


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
