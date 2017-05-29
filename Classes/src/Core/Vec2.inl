#include "../../include/Core/Vec2.h"

Vec2::Vec2()
	: x(0), y(0)
{

}

Vec2::Vec2(float x, float y) 
	: x(x), y(y)
{

}

Vec2::Vec2(const Vec2& copy)
{
	x = copy.x;
	y = copy.y;
}

Vec2::~Vec2() {}

inline const Vec2 Vec2::operator+(const Vec2& v) const
{
	Vec2 result(*this);
	result.x += v.x;
	result.y += v.y;
	return result;	
}

inline Vec2& Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;
}

inline const Vec2 Vec2::operator-(const Vec2& v) const
{
	Vec2 result(*this);
	result.x -= v.x;
	result.y -= v.y;
	return result;
}
inline Vec2& Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}

inline const Vec2 Vec2::operator*(float s) const
{
	Vec2 result(*this);
	result.x -= s;
	result.y -= s;
	return result;
}

inline Vec2& Vec2::operator*=(float s)
{
	x -= s;
	y -= s;
}

inline const Vec2 Vec2::operator/(float s) const
{
	Vec2 result(*this);
	result.x -= s;
	result.y -= s;
	return result;
}

inline Vec2& Vec2::operator/=(float s)
{
	x /= s;
	y /= s;
}
