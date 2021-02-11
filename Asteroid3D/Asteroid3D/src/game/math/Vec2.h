#pragma once

#include <cmath>

/*
* 2D Vector
*/
struct Vec2 {

	// default constructors
	Vec2() :
		x(0.0f), y(0.0f)
	{}

	Vec2(const float& f) :
		x(f),
		y(f)
	{}

	Vec2(const float& x, const float& y) :
		x(x),
		y(y)
	{}

	Vec2(const Vec2& other) :
		x(other.x),
		y(other.y)
	{}

	~Vec2() {}

	inline float length2() { return x * x + y * y; }

	inline float length() { return std::sqrtf(length2()); }

	Vec2& normalize() {
		norm();
		return *this;
	}

	void norm() {
		float oneOverLength = 1.f / length();
		x *= oneOverLength;
		y *= oneOverLength;
	}

	void norm(const float& f) {
		float oneOverLength = 1.f / f;
		x *= oneOverLength;
		y *= oneOverLength;
	}


	// operators
	Vec2& operator =(const Vec2& other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	Vec2& operator +=(const Vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& operator -=(const Vec2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vec2& operator *=(const float& f) {
		x *= f;
		y *= f;
		return *this;
	}
	Vec2& operator /=(const float& f) {
		x /= f;
		y /= f;
		return *this;
	}

	float operator [](const int& idx) {
		if (idx == 0) return x;
		else if (idx == 1) return y;
		else return 0.0f;
	}

	float operator [](const int& idx) const {
		if (idx == 0) return x;
		else if (idx == 1) return y;
		else return 0.0f;
	}

	float x, y;

};


// operators
inline Vec2 operator +(const Vec2& v1, const Vec2& v2) { return Vec2(v1.x + v2.x, v1.y + v2.y); }

inline Vec2 operator -(const Vec2& v1, const Vec2& v2) { return Vec2(v1.x - v2.x, v1.y - v2.y); }

inline Vec2 operator *(const Vec2& v1, const Vec2& v2) { return Vec2(v1.x * v2.x, v1.y * v2.y); }

inline Vec2 operator *(const Vec2& v, float f) { return Vec2(v.x * f, v.y * f); }

inline Vec2 operator *(float f, const Vec2& v) { return Vec2(f * v.x, f * v.y); }

inline Vec2 operator /(const Vec2& v1, const Vec2& v2) { return Vec2(v1.x / v2.x, v1.y / v2.y); }

inline Vec2 operator /(const Vec2& v, float f) { return Vec2(v.x / f, v.y / f); }

inline Vec2 operator /(float f, const Vec2& v) { return Vec2(f / v.x, f / v.y); }



namespace Templates {
	// Statics
	static const Vec2 Zero(0.0f, 0.0f);
	static const Vec2 UnitX(1.0f, 0.0f);
	static const Vec2 UnitY(0.0f, 1.0f);
	static const Vec2 NegUnitX(-1.0f, 0.0f);
	static const Vec2 NegUnitY(0.0f, -1.0f);

}
