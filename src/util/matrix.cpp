#include <algorithm>
#include <cassert>

namespace rok {

template <typename T>
Matrix<T>::Matrix(const int32 size_x, const int32 size_y)
		: _elements(size_x * size_y)
		, _size({ size_x, size_y }) {
	assert(size_x >= 0 && size_y >= 0);
}

template <typename T>
Matrix<T>::Matrix(const Coordinate size)
	: Matrix(size.x, size.y) {}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
		: _size(matrix.size()) {
	if (this != &matrix) {
		resize(matrix._size.x, matrix._size.y);
		std::copy_n(matrix.data(), _size.x * _size.y, _elements.begin());
	}
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
	Matrix<T> temp(matrix);
	std::swap(*this, temp);

	return *this;
}

template <typename T>
void Matrix<T>::resize(const int32 size_x, const int32 size_y) {
	assert(size_x >= 0 && size_y >= 0);

	_size.x = size_x;
	_size.y = size_y;
	_elements.resize(size_x * size_y);
}

template <typename T>
void Matrix<T>::resize(const Coordinate size) {
	resize(size.x, size.y);
}

template <typename T>
Coordinate Matrix<T>::size() const {
	return _size;
}

template <typename T>
int32 Matrix<T>::num_elements() const {
	return _size.x * _size.y;
}

template <typename T>
const T* Matrix<T>::data() const {
	return _elements.data();
}

template <typename T>
T& Matrix<T>::element(const int32 x, const int32 y) {
	assert(x >= 0 && x <= _size.x && y >= 0 && y <= _size.y);

	return _elements[x + y * _size.x];
}

template <typename T>
const T& Matrix<T>::element(const int32 x, const int32 y) const {
	assert(x >= 0 && x <= _size.x && y >= 0 && y <= _size.y);

	return _elements[x + y * _size.x];
}

template <typename T>
T& Matrix<T>::element(const Coordinate pos) {
	return element(pos.x, pos.y);
}

template <typename T>
const T& Matrix<T>::element(const Coordinate pos) const {
	return element(pos.x, pos.y);
}

} // namespace rok
