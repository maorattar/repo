#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <array>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"

class Rectangle {

public:

	//constructors
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);



	//functions

	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;

	//sharedfunctions

	void draw(Board& board) const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	Rectangle getBoundingRectangle() const;


private:
	Vertex m_left, m_right;

	Vertex getTopLeft() const;
	Vertex getBottomRight() const;

};