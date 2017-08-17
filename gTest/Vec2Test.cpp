#include "Core/Vec2.h"
#include "gtest/gtest.h"

TEST(Vec2Test, copyConstructor)
{
	Vec2 a = Vec2(1, 1);
	Vec2 b = Vec2(a);

	ASSERT_EQ(a, b)
		<< "wrong copy constructor";
}

TEST(Vec2Test, addVectors)
{
	Vec2 a = Vec2(1, 1);
	Vec2 b = Vec2(1, 1);
	Vec2 c = a + b;

	ASSERT_EQ(c, Vec2(2, 2))
		<< "incorrect vector addition";
	
	b += a;
	ASSERT_EQ(b, Vec2(2, 2))
		<< "incorrect vector addition";
}

TEST(Vec2Test, subVectors)
{
	Vec2 a = Vec2(1, 1);
	Vec2 b = Vec2(1, 1);
	Vec2 c = a - b;

	ASSERT_EQ(c, Vec2(0, 0))
		<< "incorrect vector subtraction";

	b -= a;
	ASSERT_EQ(b, Vec2(0, 0))
		<< "incorrect vector subtraction";
}

TEST(Vec2Test, multVectors)
{
	Vec2 a = Vec2(1, 1);
	Vec2 b = a * 3;
	ASSERT_EQ(b, Vec2(3, 3))
		<< "incorrect vector multiplication";

	Vec2 c = Vec2(a);
	c *= 3;

	ASSERT_EQ(c, Vec2(3, 3))
		<< "incorrect vector multiplication";
}

TEST(Vec2Test, divVectors)
{
	Vec2 a = Vec2(1, 1);
	Vec2 b = a / 2;
	ASSERT_EQ(b, Vec2(0.5, 0.5))
		<< "incorrect vector division";

	Vec2 c = Vec2(a);
	c /= 2;

	ASSERT_EQ(c, Vec2(0.5, 0.5))
		<< "incorrect vector division";
}