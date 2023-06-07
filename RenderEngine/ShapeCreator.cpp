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

const float defaultCircleStartX = 0.0f;
const float defaultCircleStartY = 0.0f;
const float defaultCircleRadius = 1.0f;
const float defaultCircleSteps = 48.0f;

extern const float defaultNgonStartX = 0.0f;
extern const float defaultNgonStartY = 0.0f;;
extern const float defaultNgonRadius = 1.0f;
extern const float defaultNgonSteps = 6.0f;

BaseShape::BaseShape() {}
BaseShape::~BaseShape() {}

QuadShape::QuadShape() {}
QuadShape::~QuadShape() {}

TriangleShape::TriangleShape() {}
TriangleShape::~TriangleShape() {}

NgonShape::NgonShape() {}
NgonShape::~NgonShape() {}

ShapeFabric::ShapeFabric() {}
ShapeFabric::~ShapeFabric() {}

std::vector<POINTFLOAT> QuadShape::createShape(const std::unordered_map<std::string, float> &data)
{
	const float startX = data.at("startX");
	const float startY = data.at("startY");
	const float width = data.at("width");
	const float height = data.at("height");

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

std::vector<POINTFLOAT> TriangleShape::createShape(const std::unordered_map<std::string, float> &data)
{
	const float startX = data.at("startX");
	const float startY = data.at("startY");
	const float width = data.at("width");
	const float height = data.at("height");

	const float halfOfWidth = width * 0.5f;
	const float halfOfHeight = height * 0.5f;

	std::vector<POINTFLOAT> vertices = {
		{ startX,		        startY + halfOfHeight },
		{ startX - halfOfWidth, startY - halfOfHeight },
		{ startX + halfOfWidth, startY - halfOfHeight }
	};

	return vertices;
}

std::vector<POINTFLOAT> NgonShape::createShape(const std::unordered_map<std::string, float> &data)
{
	const float startX = data.at("startX");
	const float startY = data.at("startY");
	const float radius = data.at("radius");
	const float steps = data.at("steps");

	const float halfOfRadius = radius * 0.5f;
	const float angle = 3.14159265358979323846 * 2 / steps;
	std::vector<POINTFLOAT> vertices;
	vertices.reserve(sizeof(POINTFLOAT) * steps);

	vertices.push_back({ startX , startY });
	for (short i = 0; i <= steps; ++i)
	{
		vertices.push_back({ halfOfRadius * sin(angle * i),
							 halfOfRadius * cos(angle * i) });
	}

	return vertices;
}

std::vector<POINTFLOAT> ShapeFabric::createBasicShape(const Shapes shapeType)
{
	std::unordered_map<std::string, float> data;
	switch (shapeType)
	{
	case Shapes::Quad:
	{
		data["startX"] = defaultQuadStartX;
		data["startY"] = defaultQuadStartY;
		data["width"] = defaultQuadWidth;
		data["height"] = defaultQuadHeight;

		return QuadShape().createShape(data);
	}
	case Shapes::Triangle:
	{
		data["startX"] = defaultTriangleStartX;
		data["startY"] = defaultTriangleStartY;
		data["width"] = defaultTriangleWidth;
		data["height"] = defaultTriangleHeight;

		return TriangleShape().createShape(data);
	}
	case Shapes::Circle:
	{
		data["startX"] = defaultCircleStartX;
		data["startY"] = defaultCircleStartY;
		data["radius"] = defaultCircleRadius;
		data["steps"] = defaultCircleSteps;

		return NgonShape().createShape(data);
	}
	case Shapes::Ngon:
	{
		data["startX"] = defaultNgonStartX;
		data["startY"] = defaultNgonStartY;
		data["radius"] = defaultNgonRadius;
		data["steps"] = defaultNgonSteps;

		return NgonShape().createShape(data);
	}
	}

	return std::vector<POINTFLOAT>();
}
