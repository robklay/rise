#include <algorithm>
#include <cassert>

namespace rok {

template <typename T>
Matrix<T>::Matrix(const int32 x, const int32 y) :
_size_x(x),
_size_y(y),
_elements(x * y) {
	assert(x >= 0 && y >= 0);
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) :
_size_x(matrix.size_x()),
_size_y(matrix.size_y()) {
	if (this != &matrix) {
		resize(matrix._size_x, matrix._size_y);
		std::copy_n(matrix.data(), _size_x * _size_y, _elements.begin());
	}
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
	if (this != &matrix) {
		resize(matrix._size_x, matrix._size_y);
		std::copy_n(matrix.data(), _size_x * _size_y, _elements.begin());
	}

	return *this;
}

template <typename T>
void Matrix<T>::resize(const int32 x, const int32 y) {
	_size_x = x;
	_size_y = y;
	_elements.resize(x * y);
}

template <typename T>
int32 Matrix<T>::size_x() const {
	return _size_x;
}

template <typename T>
int32 Matrix<T>::size_y() const {
	return _size_y;
}

template <typename T>
const T* Matrix<T>::data() const {
	return _elements.data();
}

template <typename T>
void Matrix<T>::set_element(const int32 x, const int32 y, const T color) {
	assert(x >= 0 && x <= _size_x && y >= 0 && y <= _size_y);

	_elements[x + y * _size_x] = color;
}

template <typename T>
T Matrix<T>::element(const int32 x, const int32 y) const {
	assert(x >= 0 && x <= _size_x && y >= 0 && y <= _size_y);

	return _elements[x + y * _size_x];
}

}
