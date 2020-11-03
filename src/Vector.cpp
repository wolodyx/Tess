#include "Vector.h"

#include <cfloat>


D2::D2() {}

D2::D2(double xx, double yy)
	: x(xx), y(yy) {}


D2::D2(const double* xy)
	: x(xy[0]), y(xy[1]) {}


D2 D2::operator+(const D2& other) const
{
	return D2(x + other.x, y + other.y);
}


D2 operator*(const D2& v, double k)
{
	return D2(v.x * k, v.y * k);
}

D2 operator*(double k, const D2& v)
{
	return D2(v.x * k, v.y * k);
}


bool D2::operator==(const D2& other) const
{
	return std::abs(x - other.x) <= DBL_EPSILON
		&& std::abs(y - other.y) <= DBL_EPSILON;
}


bool D2::operator!=(const D2& other) const
{
	return !(*this == other);
}


bool D3::operator==(const D3& other) const
{
	return std::abs(x - other.x) <= DBL_EPSILON
		&& std::abs(y - other.y) <= DBL_EPSILON
		&& std::abs(z - other.z) <= DBL_EPSILON;
}


bool D3::operator!=(const D3& other) const
{
	return !(*this == other);
}


D3::D3()
{
}


D3::D3(double xx, double yy, double zz)
	: x(xx), y(yy), z(zz)
{
}


D3 D3::operator-(const D3& other) const
{
	return D3(x - other.x, y - other.y, z - other.z);
}


D3 D3::operator+(const D3& other) const
{
	return D3(x + other.x, y + other.y, z + other.z);
}


D3 operator*(const D3& v, double k)
{
	return D3(v.x * k, v.y * k, v.z * k);
}

D3 operator*(double k, const D3& v)
{
	return D3(v.x * k, v.y * k, v.z * k);
}


bool Normalize(D3& v)
{
	double r = Norm(v);
	if (r < 1.0e-12)
	{
		v.x = v.y = v.z = 0.0;
		return false;
	}
	r = 1.0 / r;
	v.x *= r;
	v.y *= r;
	v.z *= r;
	return true;
}
