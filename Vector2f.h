#pragma once
#include <cmath>

struct Vector2f
{
	float x = 0.f, y = 0.f;

	Vector2f() = default;
	Vector2f(const Vector2f &vec) { x = vec.x; y = vec.y; }
	Vector2f(const float &px, const float &py) : x(px), y(py) {}

	void limit(const float &lim);
	float abs() { return std::sqrt(x * x + y * y); }
	Vector2f normalize() { return Vector2f(x / abs(), y / abs()); }
	float dot(const Vector2f &vec) { return x * vec.x + y * vec.y; }

	Vector2f add(const Vector2f &vec) { return Vector2f(x + vec.x, y + vec.y); }
	Vector2f subtract(const Vector2f &vec) { return Vector2f(x - vec.x, y - vec.y); }
	Vector2f multiply(const float &scalar) { return Vector2f(scalar * x, scalar * y); }
	
	Vector2f operator+(const Vector2f &vec) { return add(vec); }
	Vector2f &operator+=(const Vector2f &vec) { x += vec.x; y += vec.y; return *this; }
	Vector2f operator-(const Vector2f &vec) { return subtract(vec); }
	Vector2f &operator-=(const Vector2f &vec) { x -= vec.x; y -= vec.y; return *this; }
	Vector2f operator*(const float &scalar) { return multiply(scalar); }
	Vector2f &operator*=(const float &scalar) { x *= scalar; y *= scalar; return *this; }

	Vector2f &operator=(const Vector2f &vec) { x = vec.x; y = vec.y; return *this; }

};