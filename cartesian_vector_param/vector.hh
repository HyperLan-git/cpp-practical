#pragma once

#include <ostream>
#include <initializer_list>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

    Vector();
    Vector(std::initializer_list<value>);

    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);

    Vector& operator+=(const value& rhs);
    Vector& operator*=(const value& rhs);

    inline value& operator[](size_t n);
    inline const value& operator[](size_t n) const;
private:
    value data[NDIM];
};

std::ostream& operator<<(std::ostream &stream, const Vector& vec);

Vector operator+(const Vector& v1, const Vector& v2);

Vector operator*(const Vector& v1, const value& v2);
Vector operator*(const value& v1, const Vector& v2);

// Dot product
value operator*(const Vector& v1, const Vector& v2);