#pragma once
#ifndef __CORE_VECTOR_H__

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
	Vec2();

	/**
	* @brief Constructs a new vector initialized to the specified values.
	*
	* @param x The _x coordinate.
	* @param y The _y coordinate.
	*/
	Vec2(float _x, float _y);
	
	/**
	* @brief Constructs a new vector that is a copy of the specified vector.
	*
	* @param copy The vector to copy.
	*/
	Vec2(const Vec2& copy);

	~Vec2();

	inline const Vec2 operator+(const Vec2& v) const;
	inline Vec2& operator+=(const Vec2& v);
	inline const Vec2 operator-(const Vec2& v) const;
	inline Vec2& operator-=(const Vec2& v);
	inline const Vec2 operator*(float s) const;
	inline Vec2& operator*=(float s);
	inline const Vec2 operator/(float s) const;
	inline Vec2& operator/=(float s);
};

#endif // !__CORE_VECTOR_H__
