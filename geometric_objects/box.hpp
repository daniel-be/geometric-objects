#pragma once
#include "point.hpp"

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
