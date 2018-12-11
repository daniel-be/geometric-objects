#include <cmath>

#include "geometric_objects.hpp"

template <int DIM>
Point<DIM>::Point(const Point& p)
{
	for (int i = 0; i < DIM; i++) this->x[i] = p.x[i];
}

template <int DIM>
::Point<DIM>::Point(double x0, double x1, double x2)
{
	this->x[0] = x0;
	if (DIM > 1) this->x[1] = x1;
	if (DIM > 2) this->x[2] = x2;
	if (DIM > 3) throw("Constructor by coordinates not implemented for DIM > 3");
}


template <int DIM>
Point<DIM>& ::Point<DIM>::operator=(const Point& p)
{
	for (int i = 0; i < DIM; i++) this->x[i] = p.x[i];
	return *this;
}

template <int DIM>
bool Point<DIM>::operator==(const Point& p)
{
	for (int i = 0; i < DIM; i++) if (this->x[i] != p.x[i]) return false;
	return true;
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

template <int DIM>
Box<DIM>::Box(const Point<DIM>& lo, const Point<DIM>& hi) : lo(lo), hi(hi) { }

template<int DIM>
double distance(const Box<DIM>& b, const Point<DIM>& p)
{
	double d;
	for (int i = 0; i < DIM; i++)
	{
		if (p.x[i] < b.lo.x[i]) d += (b.lo.x[i] - p.x[i]) * (b.lo.x[i] - p.x[i]);
		if (p.x[i] > b.hi.x[i]) d += (p.x[i] - b.hi.x[i]) * (p.x[i] - b.hi.x[i]);
	}

	return std::sqrt(d);
}
