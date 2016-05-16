#ifndef _SHAPE_H
#define _SHAPE_H

#include <stdio.h>

class Point
{
private:
	int m_nx;
	int m_ny;
	int m_nColor;
public:
	Point() { m_nx = 0; m_ny = 0; m_nColor = 0; }
	Point(int x, int y, int c) { m_nx = x; m_ny = y; m_nColor = c; }
	void setColor(int c) { m_nColor = c; }
	int getColor() { return m_nColor; }
	void setXY(int x, int y) { m_nx = x; m_ny = y; }
	int getX() { return m_nx; }
	int getY() { return m_ny; }
	virtual	void WhoAreYou() { printf("I'm Pint\n"); }
};

class Rectangle : public Point
{
private:
	int m_nX2;
	int m_nY2;
public:
	Rectangle() : Point() { m_nX2 = 0; m_nY2 = 0; };
	Rectangle(int x1, int y1, int x2, int y2, int c) : Point(x1, y1, c) { m_nX2 = x2; m_nY2 = y2; };
	void setX2Y2(int X2, int Y2) { m_nX2 = X2; m_nY2 = Y2; }
	int getX2() { return m_nX2; }
	int getY2() { return m_nY2; }
	void WhoAreYou() { printf("I'm Rectangle\n"); }
};

#endif _SHAPE_H