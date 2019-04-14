#pragma once
#ifndef __CORE_VECTOR_H__
#define __CORE_VECTOR_H__

struct Vec2
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
	Vec2(float _x, float _y)
		: x(_x), y(_y)
	{ }

	/**
	* @brief Constructs a new vector that is a copy of the specified vector.
	*
	* @param _copy An instance to be copied.
	*/
	Vec2(const Vec2& _copy)
	{
		x = _copy.x;
		y = _copy.y;
	}

	~Vec2() {}

	inline const Vec2 operator+(const Vec2& _another) const
	{
		Vec2 result(*this);
		result.x += _another.x;
		result.y += _another.y;
		return result;
	}

	inline void operator+=(const Vec2& _another)
	{
		x += _another.x;
		y += _another.y;
	}

	inline const Vec2 operator-(const Vec2& _another) const
	{
		Vec2 result(*this);
		result.x -= _another.x;
		result.y -= _another.y;
		return result;
	}

	inline void operator-=(const Vec2& _another)
	{
		x -= _another.x;
		y -= _another.y;
	}

	inline const Vec2 operator*(float _factor) const
	{
		Vec2 result(*this);
		result.x *= _factor;
		result.y *= _factor;
		return result;
	}

	inline void operator*=(float _factor)
	{
		x *= _factor;
		y *= _factor;
	}

	inline const Vec2 operator/(float _divider) const
	{
		Vec2 result(*this);
		result.x /= _divider;
		result.y /= _divider;
		return result;
	}

	inline void operator/=(float _divider)
	{
		x /= _divider;
		y /= _divider;
	}
};

inline bool operator==(const Vec2& _lhs, const Vec2& _rhs)
{
	if (_lhs.x == _rhs.x && _lhs.y == _rhs.y)
		return true;
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
