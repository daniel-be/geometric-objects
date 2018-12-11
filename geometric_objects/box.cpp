#include "box.hpp"
#include <cmath>

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
