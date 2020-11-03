#include "gtest/gtest.h"

#include "ParametricGeometry.h"


TEST(Curve2d, Line)
{
	C12_Line line(D2(0, 0), D2(1, 0));
	D2 d;
	line.der(0, d);
	ASSERT_EQ(d, D2(1, 0));
}
