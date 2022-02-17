//
// Created by daniil on 10.11.2021.
//

#pragma once

#include <array>
#include <cstdlib>
#include <complex>
#include <functional>
#include <numeric>
#include <valarray>

template <size_t Size, class Type, typename Enable = void>
class BaseVector {
public:
    explicit BaseVector(std::array<Type, Size>& array) {};
    BaseVector& operator=(std::array<Type, Size>& array) {};
};

template <size_t Size, class Type>
class BaseVector<Size, Type,
        std::enable_if_t<std::is_same_v<std::integral_constant<size_t, Size>, std::integral_constant<size_t, 2>>>> {
public:;
    Type& x;
    Type& y;
    explicit BaseVector(std::array<Type, Size>& array) : x(array[0]), y(array[1]) {}
    BaseVector& operator=(std::array<Type, Size>& array) {
        x = array[0];
        y = array[1];
        return *this;
    };
};

template <size_t Size, class Type>
class BaseVector<Size, Type,
        std::enable_if_t<std::is_same_v<std::integral_constant<size_t, Size>, std::integral_constant<size_t, 3>>>> {
public:;
    Type& x;
    Type& y;
    Type& z;
    explicit BaseVector(std::array<Type, Size>& array) : x(array[0]), y(array[1]), z(array[2]) {}
    BaseVector& operator=(std::array<Type, Size>& array) {
        x = array[0];
        y = array[1];
        z = array[2];
        return *this;
    };
};

template <size_t Size, class Type>
class BaseVector<Size, Type,
        std::enable_if_t<std::is_same_v<std::integral_constant<size_t, Size>, std::integral_constant<size_t, 4>>>> {
public:;
    Type& x;
    Type& y;
    Type& z;
    Type& w;
    explicit BaseVector(std::array<Type, Size>& array) : x(array[0]), y(array[1]), z(array[2]), w(array[3]) {}
    BaseVector& operator=(std::array<Type, Size>& array) {
        x = array[0];
        y = array[1];
        z = array[2];
        w = array[3];
        return *this;
    };
};

template <size_t X, size_t Y, class Type>
class Matrix;

template <size_t Size, class Type>
class Vector : public BaseVector<Size, Type> {
public:
    Vector();

    template<class ...Args> requires(sizeof...(Args) == Size)
    explicit Vector(Args... args);

    Vector<Size, Type>& operator=(const Vector<Size, Type>& other);// possibly works incorrect;

    Vector(const Vector<Size, Type>& other);

    Vector(Vector<Size-1, Type> other, const Type& lastElement);

    Vector<Size, Type> operator+(const Vector<Size, Type>& other) const;

    Vector<Size, Type> operator-(const Vector<Size, Type>& other) const;

    Vector<Size, Type> operator*(const Vector<Size, Type>& other) const;

    Vector<Size, Type> operator/(const Vector<Size, Type>& other) const;

    Vector<Size, Type>& operator+=(const Vector<Size, Type>& other);

    Vector<Size, Type>& operator-=(const Vector<Size, Type>& other);

    Vector<Size, Type>& operator*=(const Vector<Size, Type>& other);

    Vector<Size, Type>& operator/=(const Vector<Size, Type>& other);

    Vector<Size, Type> operator+(const Type& value) const;

    Vector<Size, Type> operator-(const Type& value) const;

    Vector<Size, Type> operator*(const Type& value) const;

    Vector<Size, Type> operator/(const Type& value) const;

    Vector<Size, Type>& operator+=(const Type& value);

    Vector<Size, Type>& operator-=(const Type& value);

    Vector<Size, Type>& operator*=(const Type& value);

    Vector<Size, Type>& operator/=(const Type& value);

    decltype(Size) size() const;

    Vector<Size, Type> normalize();

    Type length() const;

    Type angle(Vector<Size, Type> other);

    Type& operator[](typename std::array<Type, Size>::size_type index) {
        return _data[index];
    }

    const Type& operator[](typename std::array<Type, Size>::size_type index) const {
        return _data[index];
    }

    typename std::array<Type, Size>::iterator begin();

    typename std::array<Type, Size>::const_iterator begin() const;

    typename std::array<Type, Size>::iterator end();

    typename std::array<Type, Size>::const_iterator end() const;

    template <size_t OtherSize>
    Vector<OtherSize, Type> operator*(Matrix<OtherSize, Size, Type> matrix);

    template<std::enable_if<std::is_same_v<std::integral_constant<size_t, Size>, std::integral_constant<size_t, 4>>>>
    Vector<Size, Type> rotatedX(double deg) {

    }

protected:
    std::array<Type, Size> _data;
};

template <size_t Size, class Type>
Type scalarProduct(const Vector<Size, Type>& v1, const Vector<Size, Type>& v2);

template <class Type>
Vector<3, Type> crossProduct(const Vector<3, Type>& v1, const Vector<3, Type>& v2);

template <class Type>
Vector<3, Type> perspectiveDivision(const Vector<4, Type>& vector);

template <size_t X, size_t Y, class Type>
class Matrix {
public:
    static constexpr size_t flatSize = X * Y;

    Matrix() = default;

    template<class ...Args> requires(sizeof...(Args) == X * Y)
    explicit Matrix(Args... args);

    static Matrix<X, Y, Type> Identity() {
        Matrix<X, Y, Type> result;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (i != j)
                    result[i * X + j] = 0.;
                else
                    result[i * X + j] = 1.;
            }
        }
        return result;
    }

    Vector<X, Type> column(int index) const;

    Vector<Y, Type> row(int index) const;

    Vector<X, Type> operator*(const Vector<Y, Type>& vector) const;

    template <size_t Z>
    Matrix<X, Z, Type> operator*(const Matrix<Y, Z, Type>& other) const;

    Matrix<X, Y, Type> operator*(const Type& value) const;

    Matrix<X, Y, Type> operator/(const Type& value) const;

    Matrix<Y, X, Type> transposed() const;

    Type& operator[](typename std::array<Type, flatSize>::size_type index);

    Type operator[](typename std::array<Type, flatSize>::size_type index) const;

private:
    std::array<Type, flatSize> _data;
};

//template <size_t X, class Type>
//Type determinant(const Matrix<X, X, Type>& matrix);
//
//template <size_t X, class Type>
//Type minor(Matrix<X, X, Type> matrix, size_t row, size_t column);
//
//template <size_t X, class Type>
//Matrix<X, X, Type> adjugate(Matrix<X, X, Type> matrix);
//
//template <size_t X, class Type>
//Matrix<X, X, Type> Invert(Matrix<X, X, Type> matrix);

// -----

template<size_t Size, class Type>
Vector<Size, Type>::Vector() : BaseVector<Size, Type>(_data) {}

template<size_t Size, class Type>
template<class... Args> requires(sizeof...(Args) == Size)
Vector<Size, Type>::Vector(Args... args) : _data{std::forward<Args>(args)...}, BaseVector<Size, Type>(_data) {}

template<size_t Size, class Type>
Vector<Size, Type>::Vector(Vector<Size - 1, Type> other, const Type &lastElement) : BaseVector<Size, Type>(_data) {
    for (int i = 0; const auto& element : other) _data[i++] = element;
    _data[Size - 1] = lastElement;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator+(const Vector<Size, Type> &other) const {
    auto result = *this;
    std::transform(result.begin(), result.end(), other.begin(), result.begin(), std::plus<Type>());
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator-(const Vector<Size, Type> &other) const {
    auto result = *this;
    std::transform(result.begin(), result.end(), other.begin(), result.begin(), std::minus<Type>());
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator*(const Vector<Size, Type> &other) const {
    Vector<Size, Type> result = *this;
    std::transform(result.begin(), result.end(), other.begin(), result.begin(), std::multiplies<Type>());
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator/(const Vector<Size, Type> &other) const {
    auto result = *this;
    std::transform(result.begin(), result.end(), other.begin(), result.begin(), std::divides<Type>());
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator+=(const Vector<Size, Type> &other) {
    std::transform(begin(), end(), other.begin(), begin(), std::plus<Type>());
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator-=(const Vector<Size, Type> &other) {
    std::transform(begin(), end(), other.begin(), begin(), std::minus<Type>());
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator*=(const Vector<Size, Type> &other) {
    std::transform(begin(), end(), other.begin(), begin(), std::multiplies<Type>());
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator/=(const Vector<Size, Type> &other) {
    std::transform(begin(), end(), other.begin(), begin(), std::divides<Type>());
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator+(const Type &value) const {
    auto result = *this;
    for (auto& element : result) element += value;
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator-(const Type &value) const {
    auto result = *this;
    for (auto& element : result) element -= value;
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator*(const Type &value) const {
    Vector<Size, Type> result = *this;
    for (auto& element : result) element *= value;
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::operator/(const Type &value) const {
    auto result = *this;
    for (auto& element : result) element /= value;
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator+=(const Type &value) {
    for (auto& element : _data) element += value;
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator-=(const Type &value) {
    for (auto& element : _data) element -= value;
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator*=(const Type &value) {
    for (auto& element : _data) element *= value;
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type> &Vector<Size, Type>::operator/=(const Type &value) {
    for (auto& element : _data) element /= value;
    return *this;
}

template<size_t Size, class Type>
decltype(Size) Vector<Size, Type>::size() const {
    return Size;
}

template<size_t Size, class Type>
Vector<Size, Type> Vector<Size, Type>::normalize() {
    auto len = length();
    std::for_each(begin(), end(), [len](const Type& el){return el / len;});
    return *this;
}

template<size_t Size, class Type>
Type Vector<Size, Type>::length() const {
    auto binOp = [](const Type& sum, const Type& el) {return sum + el * el;};
    return std::sqrt(std::accumulate(begin(), end(), Type(), binOp));
}

template<size_t Size, class Type>
Type Vector<Size, Type>::angle(Vector<Size, Type> other) {
    return std::acos(scalarProduct(*this, other) / (length() * other.length()));
}

template<size_t Size, class Type>
typename std::array<Type, Size>::iterator Vector<Size, Type>::begin() {
    return _data.begin();
}

template<size_t Size, class Type>
typename std::array<Type, Size>::const_iterator Vector<Size, Type>::begin() const {
    return _data.cbegin();
}

template<size_t Size, class Type>
typename std::array<Type, Size>::iterator Vector<Size, Type>::end() {
    return _data.end();
}

template<size_t Size, class Type>
typename std::array<Type, Size>::const_iterator Vector<Size, Type>::end() const {
    return _data.cend();
}

template<size_t Size, class Type>
template<size_t OtherSize>
Vector<OtherSize, Type> Vector<Size, Type>::operator*(Matrix<OtherSize, Size, Type> matrix) {
    Vector<OtherSize, Type> result;
    for (decltype(OtherSize) i = 0; i < OtherSize; i++) {
        result[i] = Type();
        for (decltype(Size) j = 0; j < Size; j++) {
            result[i] += _data[j] * matrix[j * OtherSize + i];
        }
    }
    return result;
}

template<size_t Size, class Type>
Vector<Size, Type>& Vector<Size, Type>::operator=(const Vector<Size, Type>& other) {
    _data = other._data;
    BaseVector<Size, Type>::operator=(_data);
    return *this;
}

template<size_t Size, class Type>
Vector<Size, Type>::Vector(const Vector<Size, Type> &other) : BaseVector<Size, Type>(_data) {
    _data = other._data;
    BaseVector<Size, Type>::operator=(_data);
}

template<size_t Size, class Type>
Type scalarProduct(const Vector<Size, Type> &v1, const Vector<Size, Type> &v2) {
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.);
}

template<class Type>
Vector<3, Type> crossProduct(const Vector<3, Type> &v1, const Vector<3, Type> &v2) {
    return Vector<3, Type>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.z);
}

template <class Type>
Vector<3, Type> perspectiveDivision(const Vector<4, Type>& vector) {
    return Vector<3, Type>(vector[0]/vector[3], vector[1]/vector[3], vector[2]/vector[3]);
}

template<size_t X, size_t Y, class Type>
template<class... Args> requires(sizeof...(Args) == X * Y)
Matrix<X, Y, Type>::Matrix(Args... args) : _data{std::forward<Args>(args)...} {
    static_assert(sizeof...(args) == flatSize && "Arguments amount does not match matrix size");
}

template<size_t X, size_t Y, class Type>
Vector<X, Type> Matrix<X, Y, Type>::column(int index) const {
    Vector<X, Type> result;
    for (decltype(X) i = 0; i < X; i++) result[i] = _data[i * X + index];
    return result;
}

template<size_t X, size_t Y, class Type>
Vector<Y, Type> Matrix<X, Y, Type>::row(int index) const {
    Vector<Y, Type> result;
    for (decltype(Y) i = 0; i < Y; i++) result[i] = _data[index * X + i];
    return result;
}

template<size_t X, size_t Y, class Type>
Vector<X, Type> Matrix<X, Y, Type>::operator*(const Vector<Y, Type> &vector) const {
    Vector<Y, Type> result;
    for (decltype(Y) i = 0; i < X; i++) {
        result[i] = Type();
        for (decltype(Y) j = 0; j < Y; j++) {
            result[i] += vector[j] * _data[i * X + j];
        }
    }
    return result;
}

template<size_t X, size_t Y, class Type>
template<size_t Z>
Matrix<X, Z, Type> Matrix<X, Y, Type>::operator*(const Matrix<Y, Z, Type> &other) const {
    Matrix<X, Z, Type> result;
    for (size_t i = 0; i < X; i++) {
        for (size_t j = 0; j < Z; j++) {
            result._data[i * X + j] = Type();
            for (int k = 0; k < Y; k++) {
                result[i * X + j] += _data[i * X + k] * other._data[k * Y + j];
            }
        }
    }
    return result;
}

template<size_t X, size_t Y, class Type>
Matrix<X, Y, Type> Matrix<X, Y, Type>::operator*(const Type &value) const {
    Matrix<X, Y, Type> result;
    for (decltype(X) i = 0; i < flatSize; i++) result[i] = _data[i] * value;
    return result;
}

template<size_t X, size_t Y, class Type>
Matrix<X, Y, Type> Matrix<X, Y, Type>::operator/(const Type &value) const {
    Matrix<X, Y, Type> result;
    for (decltype(X) i = 0; i < flatSize; i++) result[i] = _data[i] / value;
    return result;
}

template<size_t X, size_t Y, class Type>
Type &Matrix<X, Y, Type>::operator[](typename std::array<Type, flatSize>::size_type index) {
    return _data[index];
}

template<size_t X, size_t Y, class Type>
Type Matrix<X, Y, Type>::operator[](typename std::array<Type, flatSize>::size_type index) const {
    return _data[index];
}

//template <size_t X, class Type>
//Type determinant(const Matrix<X, X, Type>& matrix) {
//    if (X <= 1)
//        return matrix[0];
//    Type result = Type();
//    for (decltype(X) j = 0; j < X; j++) {
//        result += std::pow(-1, j) * matrix[j] * minor(matrix, 0, j);
//    }
//    return result;
//}
//
//template <class Type>
//Type determinant(const Matrix<1, 1, Type>& matrix) {
//    return matrix[0];
//}
//
//template<size_t X, class Type>
//Type minor(Matrix<X, X, Type> matrix, size_t row, size_t column) {
//    Matrix<X-1, X-1, Type> newMatrix;
//    for (decltype(X*X) i = 0, index = 0; i < X; i++)
//        for (decltype(X*X) j = 0; j < X; j++)
//            if (i != row && j != column)
//                newMatrix[index++] = matrix[i * X + j];
//    return determinant(newMatrix);
//}
//
//template <size_t X, class Type>
//Matrix<X, X, Type> adjugate(Matrix<X, X, Type> matrix) {
//    Matrix<X, X, Type> result;
//    for (decltype(X) i = 0; i < X; i++)
//        for (decltype(X) j = 0; j < X; j++)
//            result[i * X + j] = std::pow(-1, i + j) * minor(matrix, i, j);
//    return result;
//}
//
//template <size_t X, class Type>
//Matrix<X, X, Type> Invert(Matrix<X, X, Type> matrix) {
//    return adjugate(matrix) / determinant(matrix);
//}

template<size_t X, size_t Y, class Type>
Matrix<Y, X, Type> Matrix<X, Y, Type>::transposed() const {
    Matrix<Y, X, Type> result;
    for (decltype(X) i = 0; i < X; i++)
        for (decltype(Y) j = 0; j < Y; j++)
            result[j * Y + i] = _data[i * X + j];
    return result;
}