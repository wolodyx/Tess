#include "gtest/gtest.h"

#include "ParametricGeometry.h"


TEST(Curve2d, Line)
{
	C12_Line line(D2(0, 0), D2(1, 0));
	D2 d;
	line.der(0, d);
	ASSERT_EQ(d, D2(1, 0));
}


TEST(Curve2d, BaseDerCalculation)
{
	C12_Line line(D2::Orig(), D2::xAxis());
	D2 d;
	line.C12::der(0.5, d);
	ASSERT_LT(Norm(d-D2::xAxis()), 3*DBL_EPSILON);
}
