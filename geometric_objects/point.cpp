template<int DIM>
struct Point
{
	double x[DIM];

	Point(const Point& p)
	{
		for (int i = 0; i < DIM; i++) this->x[i] = p.x[i];
	}

	Point(double x0, double x1 = 0.0, double x2 = 0.0)
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