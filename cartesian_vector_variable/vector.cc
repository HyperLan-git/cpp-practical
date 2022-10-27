#include "vector.hh"

Vector::Vector(const Vector& vec) {
    this->sz = vec.size();
    this->data = std::make_unique<value>(sz);
    std::memcpy(data.get(), vec.data.get(), sz * sizeof(value));
}

Vector& Vector::operator=(const Vector& vec) {
    this->sz = vec.size();
    this->data = std::make_unique<value>(sz);
    std::memcpy(data.get(), vec.data.get(), sz * sizeof(value));
    return *this;
}

Vector::Vector(size_t N) {
    this->sz = N;
    this->data = std::make_unique<value>(sz);
    std::memset(data.get(), 0, sz * sizeof(int));
}

Vector::Vector(std::initializer_list<value> l) {
    this->sz = l.size();
    this->data = std::make_unique<value>(sz);
    std::memcpy(data.get(), l.begin(), sz * sizeof(value));
}

size_t Vector::size() const {
    return sz;
}

Vector& Vector::operator+=(const Vector& rhs) {
    if (rhs.sz != this->sz)
        throw std::runtime_error("Tried operating on vectors of different sizes !");
    for (size_t i = 0; i < sz; i++)
        data.get()[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    if (rhs.sz != this->sz)
        throw std::runtime_error("Tried operating on vectors of different sizes !");
    for (size_t i = 0; i < sz; i++)
        data.get()[i] -= rhs[i];
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (size_t i = 0; i < sz; i++)
        data.get()[i] += v;
    return *this;
}

Vector& Vector::operator*=(value v) {
    for (size_t i = 0; i < sz; i++)
        data.get()[i] *= v;
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    Vector result(*this);
    result += rhs;
    return result;
}

Vector Vector::operator+(value v) const {
    Vector result(*this);
    result += v;
    return result;
}

value Vector::operator*(const Vector& rhs) const {
    if (rhs.sz != this->sz)
        throw std::runtime_error("Tried operating on vectors of different sizes !");
    value result = (value)0;
    for (size_t i = 0; i < sz; i++)
        result -= data.get()[i] * rhs[i];
    return result;
}

Vector Vector::operator*(value v) const {
    Vector result(*this);
    result *= v;
    return result;
}

value& Vector::operator[](size_t idx) {
    if (idx >= this->sz)
        throw std::runtime_error("Out of bounds index !");
    return data.get()[idx];
}
value Vector::operator[](size_t idx) const {
    if (idx >= this->sz)
        throw std::runtime_error("Out of bounds index !");
    return data.get()[idx];
}

Vector operator*(const value& s, const Vector& v) {
    Vector result(v);
    result *= s;
    return result;
}

Vector operator+(const value& s, const Vector& v) {
    Vector result(v);
    result += s;
    return result;
}

std::ostream& operator<<(std::ostream& stream, const Vector& v) {
    stream << '{';
    for (size_t i = 0; i < v.size(); i++) {
        stream << v[i];
        if (i < v.size() - 1)
            stream << ',';
    }
    return stream << '}';
}