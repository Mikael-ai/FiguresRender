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

extern const float defaultNgonStartX;
extern const float defaultNgonStartY;
extern const float defaultNgonRadius;
extern const float defaultNgonSteps;


class BaseShape 
{
public:
	BaseShape() = default;
	~BaseShape() = default;

	/**
	*  Create shape
	*  @param data - shape instructions
	*/
	virtual std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) = 0;
};

class QuadShape : public BaseShape
{
public:
	QuadShape() = default;
	~QuadShape() = default;

	/**
	*  Create shape
	*  @param data - shape instructions
	*/
	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};

class TriangleShape : public BaseShape
{
public:
	TriangleShape() = default;
	~TriangleShape() = default;

	/**
	*  Create shape
	*  @param data - shape instructions
	*/
	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};

class NgonShape : public BaseShape
{
public:
	NgonShape() = default;
	~NgonShape() = default;

	/**
	*  Create shape
	*  @param data - shape instructions
	*/
	std::vector<POINTFLOAT> createShape(const std::unordered_map<std::string, float> &data) override;
};

class ShapeFabric
{
public:
	ShapeFabric() = default;
	~ShapeFabric() = default;

	/**
	*  Generate and return basic shape
	*  @param shapeType - type of a shape
	*/
	static std::vector<POINTFLOAT> createBasicShape(const Shapes shapeType);
};
