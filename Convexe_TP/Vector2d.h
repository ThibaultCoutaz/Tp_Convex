#pragma once
#include <iostream> 

using namespace std;

class Vector2d {

public:

	float x;
	float y;

	Vector2d() {
		x = 0.f;
		y = 0.f;
	}

	Vector2d(float _x, float _y) {
		x = _x;
		y = _y;
	}

	Vector2d operator+(const Vector2d& v) const {
		return Vector2d(x + v.x, y + v.y);
	}

	Vector2d operator-(const Vector2d& v) const {
		return Vector2d(x - v.x, y - v.y);
	}

	Vector2d operator*(const Vector2d& v) const {
		return Vector2d(x * v.x, y * v.y);
	}

	Vector2d operator/(const Vector2d& v) const {
		return Vector2d(x / v.x, y / v.y);
	}

	//Check if the Vectors have the same values.
	bool operator==(const Vector2d& v) const {
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
	Vector2d operator-() const {
		return Vector2d(-x, -y);
	}

	//Apply scalar operations.
	Vector2d operator*(const float& scalar) const {
		return Vector2d(x*scalar, y*scalar);
	}
	Vector2d operator/(const float& scalar) const {
		float mult = 1.f / scalar;
		return operator*(mult);
	}

	//Product functions
	static float DotProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.x) + (a.y * b.y));
	}

	static float CrossProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.y) - (a.y * b.x));
	}

};