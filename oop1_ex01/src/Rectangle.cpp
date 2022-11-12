#pragma once
#include <iostream>
#include "Rectangle.h"

//------------constructors--------------------

//constructor of Rectangle with two vertexes

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	//check if the vertexes are in the bounds of the array(board)
	if (bottomLeft.isValid() && topRight.isValid()) 
	{
		//checking if the vertexes are really left bottom and top right
		if (topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft))
		{
			m_left = bottomLeft;
			m_right = topRight;
		}
	}
	else //input parameters are wrong so insert default values
	{
		m_left.m_col = 20;
		m_left.m_row = 10;

		m_right.m_col = 30;
		m_right.m_row = 20;
	}

	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//constructor that gets the vertexes in array

Rectangle::Rectangle(const Vertex vertices[2])
{
	//check if the vertexes are in the bounds of the array(board)
	if (vertices[0].isValid() && vertices[1].isValid())
	{
		//checking if the vertexes are really left bottom and top right
		if (vertices[1].isHigherThan(vertices[0]) && vertices[1].isToTheRightOf(vertices[0]))
		{
			m_left = vertices[0];
			m_right = vertices[1];
		}
	}
	else //input parameters are wrong so insert default values
	{
		m_left.m_col = 20;
		m_left.m_row = 10;

		m_right.m_col = 30;
		m_right.m_row = 20;
	}
}


////////////////////////////////////////////////////////////////////////////
//constructors that gets two points from the user

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{

	Vertex bottomLeft, topRight;
	bottomLeft.m_col = x0;
	bottomLeft.m_row = y0;
	topRight.m_col = x1;
	topRight.m_row = y1;

	//check if the vertexes are in the bounds of the array(board)
	if (bottomLeft.isValid() && topRight.isValid())
	{
		//checking if the vertexes are really left bottom and top right
		if (topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft))
		{
			m_left = bottomLeft;
			m_right = topRight;
		}
	}
	else //input parameters are wrong so insert default values
	{
		m_left.m_col = 20;
		m_left.m_row = 10;

		m_right.m_col = 30;
		m_right.m_row = 20;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	Vertex topRight;
	
	topRight.m_col = start.m_col + width;
	topRight.m_row = start.m_row + height;

	//check if the vertexes are in the bounds of the array(board)
	if (start.isValid() && topRight.isValid())
	{
		//checking if the vertexes are really left bottom and top right
		if (topRight.isHigherThan(start) && topRight.isToTheRightOf(start))
		{
			m_left = start;
			m_right = topRight;
		}
	}
	else //input parameters are wrong so insert default values
	{
		m_left.m_col = 20;
		m_left.m_row = 10;

		m_right.m_col = 30;
		m_right.m_row = 20;
	}
}






//------------------functions-public-----------------//
 

//gives the user bottom left vertex
Vertex Rectangle::getBottomLeft() const
{
	return m_left;
}

////////////////////////////////////////////////////////
//gives the user top right vertex
Vertex Rectangle::getTopRight() const
{
	return m_right;
}

//////////////////////////////////////////////////////
//returns the width of the object
double Rectangle::getWidth() const
{
	return m_right.m_col - m_left.m_col;	
}

//////////////////////////////////////////////////////
//returns the heghit of the object
double Rectangle::getHeight() const
{
	return m_right.m_row - m_left.m_row;
}

///////////////////////////////////////////////////////


//--------------------shared-functions---------------------------


//function to draw the rectangle on the board

void Rectangle::draw(Board& board) const
{
	Vertex topLeft, bottomRight; 

	topLeft = getTopLeft();
	bottomRight = getBottomRight();
	//getting the other vertexes

	board.drawLine(m_left, topLeft); 
	board.drawLine(topLeft, m_right);
	board.drawLine(m_right, bottomRight);
	board.drawLine(bottomRight, m_left);
	//drawing the lines

}

//////////////////////////////////////////////////////////
//getting the area of the rectangle
double Rectangle::getArea() const
{
	double height = Rectangle::getHeight();
	double width = Rectangle::getWidth();

	return height * width;
}

////////////////////////////////////////////////////////
//this function returns the perimeter of the object
double Rectangle::getPerimeter() const
{
	double height = Rectangle::getHeight();
	double width = Rectangle::getWidth();

	return (2 * height) + (2 * width);
}

////////////////////////////////////////////////////////
//returns the center vertex of the object
Vertex Rectangle::getCenter() const
{
	Vertex center;

	center.m_col = (m_left.m_col + Rectangle::getBottomRight().m_col) / 2;
	center.m_row = (m_left.m_row + Rectangle::getTopLeft().m_row) / 2;

	return center;

}

///////////////////////////////////////////////////////////////

bool Rectangle::scale(double factor)
{
	//checking if the factor is valid
	if (factor < 0)
	{
		return false;
	}

	Vertex topRight, bottomLeft;

	Vertex middle = this->getCenter(); //getting the middle vertex from the object

	//calculating the topright vertex new x
	topRight.m_col = middle.m_col + (m_right.m_col - middle.m_col) * factor;

	//calculating the topright vertex new y
	topRight.m_row = middle.m_row + (m_right.m_row - middle.m_row) * factor;

	//calculating the bottom left vertex new x
	bottomLeft.m_col = middle.m_col - (middle.m_col - m_left.m_col) * factor;

	//calculating the bottom left vertex new y
	bottomLeft.m_row = middle.m_row - (middle.m_row - m_left.m_row) * factor;

	//checking if the new vertexes are in the boundries of the board
	if (bottomLeft.isValid() && topRight.isValid())
	{
		//checking if they are in the right places (topright and bottom left)
		if (topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft))
		{
			m_left = bottomLeft;
			m_right = topRight;
			return true;
		}
	}
	else return false;

}

///////////////////////////////////////////////////////////////
//getting the bounding rectangle returns itself in this case
Rectangle Rectangle::getBoundingRectangle() const
{
	Vertex b, t;
	
	b.m_col = this->m_left.m_col;
	b.m_row = this->m_left.m_row;
	t.m_col = this->m_right.m_col;
	t.m_row = this->m_right.m_row;

	Rectangle r(b , t);

	return r;
}

//////////////////////////////////////////////////////////////////

//--------------------private-functions---------------

//function that returns the bottom right vertex
Vertex Rectangle::getBottomRight() const
{
	Vertex bottomRight;

	bottomRight.m_col = m_right.m_col;
	bottomRight.m_row = m_left.m_row;

	return bottomRight;
}

/////////////////////////////////////////////////////////////
//function that returns the topleft vertex
Vertex Rectangle::getTopLeft() const
{
	Vertex topLeft;

	topLeft.m_col = m_left.m_col;
	topLeft.m_row = m_right.m_row;

	return topLeft;


}

///////////////////////////////////////////////////////////
