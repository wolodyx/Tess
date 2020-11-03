#include "ParametricGeometry.h"


void C23::normal(const D2& uv, D3& n) const
{
	D3 du, dv;
	this->ders(uv, &du, &dv);
	n = Cross(du, dv);
	Normalize(n);
}


C12_Line::C12_Line(const D2& orig, const D2& dir)
	: m_orig(orig), m_dir(dir)
{
}


C12_Line::~C12_Line()
{
}


void C12_Line::domain(D2& dom) const
{
	dom.x = 0.0;
	dom.y = 1.0;
}


void C12_Line::point(double t, D2& point) const
{
	point = m_orig + t * m_dir;
}


void C12_Line::der(double, D2& d) const
{
	d = m_dir;
}


C23_Plane::C23_Plane(const D3& point1, const D3& point2, const D3& point3)
{
	m_orig = point1;
	m_e1 = point2 - point1, m_e2 = point3 - point1;
	m_normal = Cross(m_e1, m_e2);
	Normalize(m_normal);
}


C23_Plane::~C23_Plane()
{
}


void C23_Plane::domain(D2& uv0, D2& uv1) const
{
	uv0.x = 0.0, uv0.y = 0.0;
	uv1.x = 1.0, uv1.y = 1.0;
}


void C23_Plane::point(const D2& uv, D3& point) const
{
	point = m_orig + uv.x * m_e1 + uv.y * m_e2;
}


void C23_Plane::ders(const D2& uv, D3* du, D3* dv) const
{
	if (du)
		(*du) = m_e1;
	if (dv)
		(*dv) = m_e2;
}


void C23_Plane::normal(const D2& uv, D3& n) const
{
	n = m_normal;
}
