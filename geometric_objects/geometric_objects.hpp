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

template<int DIM>
struct Line_segment
{
	Point<DIM> s, e;
};

template<int DIM>
struct Box
{
	Point<DIM> lo, hi;
	Box();
	Box(const Point<DIM>& lo, const Point<DIM>& hi);
	~Box();
};

template<int DIM>
double distance(const Box<DIM>& b, const Point<DIM>& p);