#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <array>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"


class IsoscelesTriangle
{
	public:
//----------------------constructors-----------------------

	IsoscelesTriangle(const Vertex vertices[3]);

private:
	Vertex m_bottomLeft;
	Vertex m_top;
	Vertex m_bottomRight;

	double distance(const Vertex vertex1, const Vertex vertex2);

};