#pragma once
#include <cmath>

template<int DIM>
struct Point
{
	double x[DIM];

	Point(const Point& p);

	Point(double x0 = 0.0, double x1 = 0.0, double x2 = 0.0)
	{
		this->x[0] = x0;
		if (DIM > 1) this->x[1] = x1;
		if (DIM > 2) this->x[2] = x2;
		if (DIM > 3) throw("Constructor by coordinates not implemented for DIM > 3");
	}

	Point& operator=(const Point& p)
	{
		for (int i = 0; i < DIM; i++) this->x[i] = p.x[i];
		return *this;
	}

	bool operator==(const Point& p)
	{
		for (int i = 0; i < DIM; i++) if (this->x[i] != p.x[i]) return false;
		return true;
	}
};

template<int DIM>
struct Line_segment
{
	Point<DIM> s, e;
};

template <int DIM>
Point<DIM>::Point(const Point& p)
{
	for (int i = 0; i < DIM; i++) this->x[i] = p.x[i];
}

template<int DIM>
double distance(const Point<DIM>& p, const Point<DIM>& q)
{
	double d;
	for (int i = 0; i < DIM; i++)
	{
		if (p.x[i] < q.x[i]) d += (q.x[i] - p.x[i]) * (q.x[i] - p.x[i]);
		else d += (p.x[i] - q.x[i]) * (p.x[i] - q.x[i]);
	}

	return std::sqrt(d);
}
