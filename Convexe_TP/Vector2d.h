#pragma once
#include <iostream> 
#include "Global.h"

using namespace std;

class Vector2d {

public:

	float x;
	float y;

	Vector2d();
	Vector2d(float _x, float _y);

	inline Vector2d operator+(const Vector2d& v) const {
		return Vector2d(x + v.x, y + v.y);
	}

	inline Vector2d operator-(const Vector2d& v) const {
		return Vector2d(x - v.x, y - v.y);
	}

	inline Vector2d operator*(const Vector2d& v) const {
		return Vector2d(x * v.x, y * v.y);
	}

	inline Vector2d operator/(const Vector2d& v) const {
		return Vector2d(x / v.x, y / v.y);
	}

	//Check if the Vectors have the same values.
	inline bool operator==(const Vector2d& v) const {
		return(x == v.x && y == v.y);
	}

	/*Check which Vectors are closer or further from the
	origin.
	bool operator>(const Vector2d&) const;
	bool operator<(const Vector2d&) const;
	bool operator>=(const Vector2d&) const;
	bool operator<=(const Vector2d&) const;*/

	friend ostream& operator<<(ostream& os, const Vector2d& v)
	{
		os << "x = " << v.x << "//y = " << v.y << "\n";
		return os;
	}

	//Negate both the x and y values.
	inline Vector2d operator-() const {
		return Vector2d(-x, -y);
	}

	//Apply scalar operations.
	inline Vector2d operator*(const float& scalar) const {
		return Vector2d(x*scalar, y*scalar);
	}
	inline Vector2d operator/(const float& scalar) const {
		float mult = 1.f / scalar;
		return operator*(mult);
	}

	//Product functions
	inline static float DotProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.x) + (a.y * b.y));
	}

	inline static float CrossProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.y) - (a.y * b.x));
	}

	inline float LengthSquared() const {
		return x*x + y*y;
	}


	inline float Length() const {
		return sqrt(LengthSquared());
	}

	inline static Vector2d Normalize(Vector2d v)
	{
		return v/v.LengthSquared();
	}

	static Vector2d Random(float, float, float, float);

	//Negate both the x and y values.
	inline Vector2d rotate90AntiClockwise() const {
		return Vector2d(-y, x);
	}

	inline Vector2d rotate90Clockwise() const {
		return Vector2d(y, -x);
	}
};