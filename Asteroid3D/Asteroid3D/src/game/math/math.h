#pragma once

#include <cmath>
#include <memory.h>
#include <limits>

namespace Math {

	/*
	* Constants
	*/
	constexpr float PI = 3.1415926535f;
	constexpr float PI2 = PI * 2.0f;
	constexpr float PIOver2 = PI / 2.0f;
	constexpr float INF = std::numeric_limits<float>::infinity();
	constexpr float NEGINF = INF * -1;

	/*
	* Formulas
	*/

	inline float ToRadians(const float& degrees) { return degrees * PI / 180.0f; }

	inline float ToDegrees(const float& radians) { return radians * 180.0f / PI; }

	inline bool NearZero(const float& val, float epsilon = 0.001f) { return (fabs(val <= epsilon) ? true : false); }

	template <typename T>
	T Max(const T& a, const T& b) { return (a < b ? b : a); }

	template <typename T>
	T Min(const T& a, const T& b) { return (a < b ? a : b); }

	template <typename T>
	T Clamp(const T& value, const T& lower, const T& upper) { return Min(upper, Max(lower, value)); }

	inline float Abs(const float& value) { return fabs(value); }

	inline float Cos(const float& angle) { return cosf(angle); }

	inline float Sin(const float& angle) { return sinf(angle); }

	inline float Tan(const float& angle) { return tanf(angle); }

	inline float Acos(const float& value) { return acosf(value); }

	inline float Atan2(const float& y, const float& x) { return atan2f(y, x); }

	inline float Cot(float angle) { return 1.0f / Tan(angle); }

	inline float Lerp(float a, float b, float f) { return a + f * (b - a); }

	inline float Sqrt(float value) { return sqrtf(value); }

	inline float Fmod(float numer, float denom) { return fmod(numer, denom); }

}
