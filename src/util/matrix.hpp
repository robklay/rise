#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "types.hpp"

namespace rok {

// A 2-dimensional std::vector-based container.
template <typename T>
class Matrix {
public:
	Matrix(const int32 x = 0, const int32 y = 0);
	Matrix(const Matrix<T>& matrix);
	Matrix<T>& operator=(const Matrix<T>& matrix);

	void resize(const int32 x, const int32 y);
	int32 size_x() const;
	int32 size_y() const;

	// Returns a direct pointer to the memory array used internally.
	const T* data() const;

	void set_element(const int32 x, const int32 y, const T color);
	T element(const int32 x, const int32 y) const;

private:
	int32 _size_x;
	int32 _size_y;
	std::vector<T> _elements;
};

}

#include "matrix.cpp"
