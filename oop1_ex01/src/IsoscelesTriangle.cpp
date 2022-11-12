#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <array>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "IsoscelesTriangle.h"

//---------------------------constructors------------------------------
IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
{
	if (vertices[0].isValid() && vertices[1].isValid() && vertices[2].isValid())
	{
		if (vertices[0].m_row == vertices[2].m_row) // Check if equivalent to x acces
		{
			if (distance(vertices[0], vertices[1]) == distance(vertices[2], vertices[1]))
			{
				m_bottomLeft = vertices[0];
				m_top = vertices[1];
				m_bottomRight = vertices[2];
			}
		}
	}

	else
	{
		m_bottomLeft.m_col = 20;
		m_bottomLeft.m_row = 20;
		m_top.m_col = 25;
		m_top.m_row = 25;
		m_bottomRight.m_col = 30;
		m_bottomRight.m_row = 20;
	}
}






//-------------------------privateFunctions---------------------------

double IsoscelesTriangle::distance(const Vertex vertex1, const Vertex vertex2)
{
	double a,b, c;

	a = (vertex2.m_col - vertex1.m_col);
	b = (vertex2.m_row - vertex1.m_row);

	a *= a;
	b *= b;
	c = a + b;
	return sqrt(c);
	
}