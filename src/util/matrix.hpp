#pragma once

#include <vector>

#include "coordinate.hpp"
#include "types.hpp"

namespace rok {

// A 2-dimensional std::vector-based container.
template <typename T>
class Matrix {
public:
	Matrix(const Coordinate size = { 0, 0 });
	Matrix(const Matrix<T>& matrix);
	Matrix<T>& operator=(const Matrix<T>& matrix);

	void resize(const int32 x, const int32 y);
	Coordinate size() const;

	// Returns a direct pointer to the memory array used internally.
	const T* data() const;

	void set_element(const int32 x, const int32 y, const T color);
	T element(const int32 x, const int32 y) const;

private:
	Coordinate _size;
	std::vector<T> _elements;
};

} // namespace rok

#include "matrix.cpp"
