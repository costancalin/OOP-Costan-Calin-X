#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int height, int width)
{
	this->height = height;
	this->width = width;

	m = new char* [height];
	int i = 0, j= 0;
	for (i = 0; i < height; i++)
	{
		m[i] = new char [width];
		for (j = 0; j < width; j++)
			m[i][j] = ' ';
	}
}


void Canvas::DrawCircle(int x, int y, int ray, char ch) 
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
				m[i][j] = ch;
}


void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				m[i][j] = ch;
}


void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++) 
	{
		if (i >= 0 && i < height)
		{
			if (left >= 0 && left < width) m[i][left] = ch;
			if (right >= 0 && right < width) m[i][right] = ch;
		}
	}
	for (int j = left; j <= right; j++)
	{
		if (j >= 0 && j < width) 
		{
			if (top >= 0 && top < height) m[top][j] = ch;
			if (bottom >= 0 && bottom < height) m[bottom][j] = ch;
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) 
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			if (i >= 0 && i < height && j >= 0 && j < width)
				m[i][j] = ch;
}


void Canvas::SetPoint(int x, int y, char ch) 
{
		m[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) 
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);

	int sx;
	if (x1 < x2)
	{
		sx = 1;
	}
	else 
	{
		sx = -1;
	}

	int sy;
	if (y1 < y2)
	{
		sy = 1;
	}
	else 
	{
		sy = -1;
	}

	int er = dx + dy;

	while (true) 
	{
		if (x1 >= 0) 
		{
			if (x1 < width)
			{
				if (y1 >= 0)
				
				{
					if (y1 < height) 
					{
						m[y1][x1] = ch;
					}
				}
			}
		}

		if (x1 == x2) 
		{
			if (y1 == y2) 
			{
				break;
			}
		}

		int e2 = 2 * er;
		if (e2 >= dy) 
		{
			er = er + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx) 
		{
			er = er + dx;
			y1 = y1 + sy;
		}
	}
}


void Canvas::Print() 
{
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
			cout << m[i][j];
		cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			m[i][j] = ' ';
}





