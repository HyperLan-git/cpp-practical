#include "vector.hh"

Vector::Vector() : data{0} {}

Vector::Vector(std::initializer_list<value> vals) {
    size_t i = 0;
    for(const value& val : vals)
    {
        data[i++] = val;
    }
}

Vector& Vector::operator+=(const Vector& rhs) {
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    for (size_t i = 0; i < NDIM; i++)
        data[i] -= rhs[i];
    return *this;
}

Vector& Vector::operator+=(const value& rhs) {
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs;
    return *this;
}

Vector& Vector::operator*=(const value& rhs) {
    for (size_t i = 0; i < NDIM; i++)
        data[i] *= rhs;
    return *this;
}

inline value& Vector::operator[](size_t n) {
    if (n > NDIM) throw std::out_of_range("Not a valid index : " + std::to_string(n));
    return data[n];
}

inline const value& Vector::operator[](size_t n) const {
#ifdef CHECKS
    if (n > NDIM) throw std::out_of_range("Not a valid index : " + std::to_string(n));
#endif
    return data[n];
}


std::ostream& operator<<(std::ostream &stream, const Vector &vec) {
    stream << '{';
    for (size_t i = 0; i < NDIM; i++) {
        stream << vec[i];
        if (i < NDIM - 1)
            stream << ',';
    }
    return stream << '}';
}

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector res;
    for (size_t i = 0; i < NDIM; i++)
        res[i] = v1[i] + v2[i];
    return res;
}

Vector operator*(const Vector& v1, const value& v2) {
    Vector res;
    for (size_t i = 0; i < NDIM; i++)
        res[i] = v1[i] * v2;
    return res;
}

Vector operator*(const value& v1, const Vector& v2) {
    return v2 * v1;
}

value operator*(const Vector& v1, const Vector& v2) {
    value result = v1[0] * v2[0];
    for (size_t i = 1; i < NDIM; i++)
        result += v1[i] * v2[i];
    return result;
}