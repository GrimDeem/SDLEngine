#pragma once
#ifndef __CORE_VECTOR_H__
#define __CORE_VECTOR_H__

class Vec2
{
public:
	/**
	* The x coordinate.
	*/
	float x;

	/**
	* The y coordinate.
	*/
	float y;

	/**
	* @brief Constructs a new vector initialized to all zeros.
	*/

	Vec2()
		: x(0), y(0)
	{ }

	/**
	* @brief Constructs a new vector initialized to the specified values.
	*
	* @param x The _x coordinate.
	* @param y The _y coordinate.
	*/
	Vec2(float x, float y) 
		: x(x), y(y)
	{ }
	
	/**
	* @brief Constructs a new vector that is a copy of the specified vector.
	*
	* @param copy The vector to copy.
	*/	
	Vec2(const Vec2& copy)
	{
		x = copy.x;
		y = copy.y;
	}

	~Vec2() {}

	inline const Vec2 operator+(const Vec2& v) const
	{
		Vec2 result(*this);
		result.x += v.x;
		result.y += v.y;
		return result;	
	}

	inline void operator+=(const Vec2& v)
	{
		x += v.x;
		y += v.y;
	}

	inline const Vec2 operator-(const Vec2& v) const
	{
		Vec2 result(*this);
		result.x -= v.x;
		result.y -= v.y;
		return result;
	}

	inline void operator-=(const Vec2& v)
	{
		x -= v.x;
		y -= v.y;
	}

	inline const Vec2 operator*(float s) const
	{
		Vec2 result(*this);
		result.x *= s;
		result.y *= s;
		return result;
	}

	inline void operator*=(float s)
	{
		x *= s;
		y *= s;
	}

	inline const Vec2 operator/(float s) const
	{
		Vec2 result(*this);
		result.x /= s;
		result.y /= s;
		return result;
	}

	inline void operator/=(float s)
	{
		x /= s;
		y /= s;
	}
};
	
inline bool operator==(const Vec2& lhs, const Vec2& rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y)
		return true;
	else
		return false;
}

struct Size
{
	Size()
		: width(0)
		, height(0)
	{}
	
	Size(int _width, int _height)
		: width(_width)
		, height(_height)
	{}
	int width, height;
};
#endif // !__CORE_VECTOR_H__
