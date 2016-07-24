#include <algorithm>
#include <cassert>

namespace rok {

template <typename T>
Matrix<T>::Matrix(const Coordinate size) :
_size(size),
_elements(size.x * size.y) {
	assert(size.x >= 0 && size.y >= 0);
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) :
_size(matrix.size()) {
	if (this != &matrix) {
		resize(matrix._size.x, matrix._size.y);
		std::copy_n(matrix.data(), _size.x * _size.y, _elements.begin());
	}
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
	if (this != &matrix) {
		resize(matrix._size.x, matrix._size.y);
		std::copy_n(matrix.data(), _size.x * _size.y, _elements.begin());
	}

	return *this;
}

template <typename T>
void Matrix<T>::resize(const int32 x, const int32 y) {
	_size.x = x;
	_size.y = y;
	_elements.resize(x * y);
}

template <typename T>
Coordinate Matrix<T>::size() const {
	return _size;
}

template <typename T>
const T* Matrix<T>::data() const {
	return _elements.data();
}

template <typename T>
void Matrix<T>::set_element(const int32 x, const int32 y, const T color) {
	assert(x >= 0 && x <= _size.x && y >= 0 && y <= _size.y);

	_elements[x + y * _size.x] = color;
}

template <typename T>
T Matrix<T>::element(const int32 x, const int32 y) const {
	assert(x >= 0 && x <= _size.x && y >= 0 && y <= _size.y);

	return _elements[x + y * _size.x];
}

} // namespace rok
