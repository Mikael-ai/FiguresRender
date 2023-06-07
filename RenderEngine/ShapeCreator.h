#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Shapes.h"

extern const float defaultQuadStartX;
extern const float defaultQuadStartY;
extern const float defaultQuadWidth;
extern const float defaultQuadHeight;

extern const float defaultTriangleStartX;
extern const float defaultTriangleStartY;
extern const float defaultTriangleWidth;
extern const float defaultTriangleHeight;

extern const float defaultCircleStartX;
extern const float defaultCircleStartY;
extern const float defaultCircleRadius;
extern const float defaultCircleSteps;


class BaseShape {
public:
	BaseShape();
	~BaseShape();

	virtual std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) = 0;
};

class QuadShape : public BaseShape
{
public:
	QuadShape();
	~QuadShape();

	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};

class TriangleShape : public BaseShape
{
public:
	TriangleShape();
	~TriangleShape();

	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};

class CircleShape : public BaseShape
{
public:
	CircleShape();
	~CircleShape();

	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};


class ShapeFabric
{
public:
	static std::vector<POINTFLOAT> createBasicShape(const Shapes shapeType);
};
