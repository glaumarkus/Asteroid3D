#pragma once

#include <cmath>

constexpr float EPSILON = 0.00001f;


/*
* 4D Vector
*/
struct Vec4 {

	// default constructors
	Vec4() :
		x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{}

	Vec4(const float& f) :
		x(f),
		y(f),
		z(f),
		w(0.0f)
	{}

	Vec4(const float& x, const float& y, const float& z) :
		x(x),
		y(y),
		z(z),
		w(0.0f)
	{}

	Vec4(const float& x, const float& y, const float& z, const float& w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	~Vec4() {}

	// copy constructor
	Vec4(const Vec4& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}

	float length2() { return x * x + y * y + z * z + w * w; }

	float length() { return std::sqrt(length2()); }

	Vec4& normalize() {
		norm();
		return *this;
	}

	void norm() {
		float oneOverLength = 1.f / length();
		x *= oneOverLength;
		y *= oneOverLength;
		z *= oneOverLength;
		w *= oneOverLength;
	}

	void norm(const float& f) {
		float oneOverLength = 1.f / f;
		x *= oneOverLength;
		y *= oneOverLength;
		z *= oneOverLength;
		w *= oneOverLength;
	}


	// operators
	Vec4& operator =(const Vec4& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	Vec4& operator +=(const Vec4& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vec4& operator -=(const Vec4& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}
	Vec4& operator *=(float f) {
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return *this;
	}
	Vec4& operator /=(float f) {
		x /= f;
		y /= f;
		z /= f;
		w /= f;
		return *this;
	}

	float operator [](const int& idx) {
		if (idx == 0) return x;
		else if (idx == 1) return y;
		else if (idx == 2) return z;
		else if (idx == 3) return w;
		else return 0.0f;
	}

	float operator [](const int& idx) const {
		if (idx == 0) return x;
		else if (idx == 1) return y;
		else if (idx == 2) return z;
		else if (idx == 3) return w;
		else return 0.0f;
	}

	// vars
	float x, y, z, w;

};


// add operators
Vec4 operator +(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w);
}

Vec4 operator -(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w);
}

Vec4 operator *(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z,
		v1.w * v2.w);
}

Vec4 operator *(const Vec4& v, float f)
{
	return Vec4(v.x * f,
		v.y * f,
		v.z * f,
		v.w * f);
}

Vec4 operator *(float f, const Vec4& v)
{
	return Vec4(f * v.x,
		f * v.y,
		f * v.z,
		f * v.w);
}

Vec4 operator /(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z,
		v1.w / v2.w);
}

Vec4 operator /(const Vec4& v, float f)
{
	return Vec4(v.x / f,
		v.y / f,
		v.z / f,
		v.w / f);
}

Vec4 operator /(float f, const Vec4& v)
{
	return Vec4(f / v.x,
		f / v.y,
		f / v.z,
		f / v.w);
}


// Vector operations

// dot
float dot(const Vec4& v1, const Vec4& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// cross
Vec4 cross(const Vec4& v1, const Vec4& v2) {
	return
		Vec4(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
}

// reflect
Vec4 reflect(const Vec4& v1, const Vec4& v2) {
	return Vec4(v1 - v2 * 2.0f * dot(v1, v2));
}

// basic operations
bool equal(const float& f1, const float& f2) {
	if (std::abs(f1 - f2) < EPSILON)
		return true;
	return false;
}

namespace Templates {

	// Statics
	static const Vec4 Zero(0.0f, 0.0f, 0.0f, 0.0f);

	static const Vec4 UnitX(1.0f, 0.0f, 0.0f, 0.0f);
	static const Vec4 UnitY(0.0f, 1.0f, 0.0f, 0.0f);
	static const Vec4 UnitZ(0.0f, 0.0f, 1.0f, 0.0f);
	static const Vec4 UnitW(0.0f, 0.0f, 0.0f, 1.0f);

	static const Vec4 NegUnitX(-1.0f, 0.0f, 0.0f, 0.0f);
	static const Vec4 NegUnitY(0.0f, -1.0f, 0.0f, 0.0f);
	static const Vec4 NegUnitZ(0.0f, 0.0f, -1.0f, 0.0f);
	static const Vec4 NegUnitW(0.0f, 0.0f, 0.0f, -1.0f);



}

