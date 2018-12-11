#pragma once
template<int DIM>
struct Point
{
	double x[DIM];

	Point(const Point& p);
	Point(double x0 = 0.0, double x1 = 0.0, double x2 = 0.0);
	Point& operator=(const Point& p);
	bool operator==(const Point& p);
};

template<int DIM>
double distance(const Point<DIM>& p, const Point<DIM>& q);