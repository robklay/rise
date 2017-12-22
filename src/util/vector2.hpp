#pragma once

#include <cmath>
#include <type_traits>

#include "math.hpp"

namespace rok {

template <typename T>
class Vector2 {
	static_assert(std::is_arithmetic<T>::value, "type of Vector2 must be arithmetic");

public:
	Vector2() = default;
	Vector2(const T x, const T y) : x(x), y(y) {}

	Vector2<T> normalized() const;
	double magnitude() const;
	double magnitude_squared() const;
	double direction() const;

	T x = 0;
	T y = 0;
};

template <typename T>
inline Vector2<T> Vector2<T>::normalized() const {
	const double mag = magnitude();
	return Vector2(x / mag, y / mag);
}

template <typename T>
inline double Vector2<T>::magnitude() const {
	return std::sqrt(magnitude_squared());
}

template <typename T>
inline double Vector2<T>::magnitude_squared() const {
	return static_cast<double>(x * x + y * y);
}

template <typename T>
inline double Vector2<T>::direction() const {
	return (std::atan2(y, x) * RAD_TO_DEG_FACTOR) % 360.0;
}

template <typename T>
inline Vector2<T> operator-(const Vector2<T> right) {
	return Vector2(-right.x, -right.y);
}

template <typename T>
inline Vector2<T> operator+(const Vector2<T> left, const Vector2<T> right) {
	return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
inline Vector2<T> operator-(const Vector2<T> left, const Vector2<T> right) {
	return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
inline Vector2<T> operator+=(Vector2<T>& left, const Vector2<T> right) {
	left.x += right.x;
	left.y += right.y;

	return left;
}

template <typename T>
inline Vector2<T> operator-=(Vector2<T>& left, const Vector2<T> right) {
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

template <typename T>
inline Vector2<T> operator*(const Vector2<T> left, const double right) {
	return Vector2<T>(left.x * right, left.y * right);
}

template <typename T>
inline Vector2<T> operator*(const double left, const Vector2<T> right) {
	return Vector2<T>(right * left);
}

template <typename T>
inline Vector2<T> operator/(const Vector2<T> left, const double right) {
	return Vector2<T>(left.x / right, left.y / right);
}

template <typename T>
inline Vector2<T> operator/(const double left, const Vector2<T> right) {
	return Vector2<T>(left / right.x, left / right.y);
}

template <typename T>
inline Vector2<T> operator*=(Vector2<T>& left, const Vector2<T> right) {
	left.x *= right.x;
	left.y *= right.y;

	return left;
}

template <typename T>
inline Vector2<T> operator/=(Vector2<T>& left, const Vector2<T> right) {
	left.x /= right.x;
	left.y /= right.y;

	return left;
}

template <typename T>
inline bool operator==(const Vector2<T> left, const Vector2<T> right) {
	return left.x == right.x && left.y == right.y;
}

template <typename T>
inline bool operator!=(const Vector2<T> left, const Vector2<T> right) {
	return !(left == right);
}

} // namespace rok
