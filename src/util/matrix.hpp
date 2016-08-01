#pragma once

#include <vector>

#include "coordinate.hpp"
#include "types.hpp"

namespace rok {

// A 2-dimensional dynamic container.
template <typename T>
class Matrix {
public:
	Matrix() = default;
	Matrix(const int32 size_x, const int32 size_y);
	Matrix(const Coordinate size);
	Matrix(const Matrix<T>& matrix);
	Matrix<T>& operator=(const Matrix<T>& matrix);

	void resize(const int32 size_x, const int32 size_y);
	void resize(const Coordinate size);
	Coordinate size() const;
	int32 num_elements() const;

	// Returns a pointer to the memory array used internally.
	const T* data() const;

	T& element(const int32 x, const int32 y);
	const T& element(const int32 x, const int32 y) const;
	T& element(const Coordinate pos);
	const T& element(const Coordinate pos) const;

private:
	std::vector<T> _elements;
	Coordinate _size;
};

} // namespace rok

#include "matrix.cpp"
