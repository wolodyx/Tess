#ifndef TESS_GEO_Vector_h_
#define TESS_GEO_Vector_h_

#include <cmath>


struct D2
{
	double x, y;

	D2();
	D2(double xx, double yy);
	D2(const double* xy);
	D2 operator+(const D2& other) const;
	bool operator==(const D2& other) const;
	bool operator!=(const D2& other) const;
};

D2 operator*(const D2& v, double k);
D2 operator*(double k, const D2& v);


struct D3
{
	double x, y, z;

	D3();
	D3(double xx, double yy, double zz);
	D3 operator-(const D3& other) const;
	D3 operator+(const D3& other) const;
	bool operator==(const D3& other) const;
	bool operator!=(const D3& other) const;
};

D3 operator*(const D3& v, double k);
D3 operator*(double k, const D3& v);


//! Векторное произведение в правом ортонормированном базисе.
inline D3 Cross(const D3& a, const D3& b)
{
	return D3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}


inline double Norm(const D3& v)
{
	return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


bool Normalize(D3& v);

#endif // TESS_GEO_Vector_h_
