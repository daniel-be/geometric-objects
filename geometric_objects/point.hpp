#pragma once
template<int DIM>
struct Point
{
	Point(const Point& p);
	Point(double x0 = 0.0, double x1 = 0.0, double x2 = 0.0);
	Point& operator=(const Point& p);
	bool operator==(const Point& p);
};