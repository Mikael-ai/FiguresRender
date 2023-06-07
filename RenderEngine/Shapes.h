#pragma once


enum Shapes {
	Quad,
	Triangle,
	Circle,
	Ngon
};

struct ShapesEntry
{
	short id;
	Shapes shape;
};

const ShapesEntry shapesEntry[]
{
	{ 0, Quad },
	{ 1, Triangle },
	{ 2, Circle },
	{ 3, Ngon }
};
