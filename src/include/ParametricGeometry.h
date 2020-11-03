#ifndef TESS_GEO_ParametricGeometry_h_
#define TESS_GEO_ParametricGeometry_h_

#include <cmath>

#include "Vector.h"


class C12
{
public:
	virtual ~C12() {}
	virtual void domain(D2&) const = 0;
	virtual void point(double t, D2& point) const = 0;
	virtual void der(double t, D2&) const = 0;
};


class C13
{
public:
	virtual ~C13() {}
	virtual void domain(D2&) const = 0;
	virtual void point(double t, D3& point) const = 0;
	virtual void der(double t, D3&) const = 0;
};


class C23
{
public:

	virtual ~C23() {}
	virtual void domain(D2& uv0, D2& uv1) const = 0;
	virtual void point(const D2& uv, D3& point) const = 0;
	virtual void ders(const D2& uv, D3* du, D3* dv) const = 0;
	virtual void normal(const D2& uv, D3& normal) const;
};


class C12_Line : public C12
{
	D2 m_orig;
	D2 m_dir;
public:

	C12_Line(const D2& orig, const D2& dir);
	virtual ~C12_Line();
	virtual void domain(D2& dom) const;
	virtual void point(double t, D2& point) const;
	virtual void der(double, D2& d) const;
};


class C23_Plane : public C23
{
	D3 m_orig, m_e1, m_e2, m_normal;
public:
	//! Плоскость по трем точкам.
	C23_Plane(const D3& point1, const D3& point2, const D3& point3);
	virtual ~C23_Plane();
	virtual void domain(D2& uv0, D2& uv1) const;
	virtual void point(const D2& uv, D3& point) const;
	virtual void ders(const D2& uv, D3* du, D3* dv) const;
	virtual void normal(const D2& uv, D3& normal) const;
};
#endif // TESS_GEO_ParametricGeometry_h_
