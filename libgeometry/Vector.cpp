#include <cmath>

#include "Vector.h"

using namespace geometry;
using namespace std;

// exception
VectorLengthException::VectorLengthException()
    : GeometryException("Vector length cannot be zero")
{
}

VectorLengthException::VectorLengthException(const string& what)
    : GeometryException(what)
{
}

// ctr
Vector::Vector()
{
}

Vector::Vector(double x, double y, double z)
    : Point(x, y, z)
{
}

Vector::Vector(const Point& point)
    : Point(point)
{
}

Vector::Vector(const Point& p1, const Point& p2)
{
    // mojem da polzvame nagotovo:
    // * suzdavane na vector ot tochka
    // * izvajdane na vectori: p2 - p1, poneje iskame da zapazim
    //   posokata, no da zapochva ot nulata
    // * default copy-assignment operator
    *this = Vector(p2) - Vector(p1);
}

// methods
double Vector::length() const
{
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::direction() const
{
    double len = length();

    if (len == 0) {
        throw VectorLengthException();
    }

    return Vector(x / len, y / len, z / len);
}

bool Vector::isZero() const
{
    return x == 0 && y == 0 && z == 0;
}

bool Vector::isParallel(const Vector& other) const
{
    if (isZero() || other.isZero()) {
        throw VectorLengthException();
    }

    if (this->getX() / other.getX() == this->getY() / other.getY() == this->getZ() / other.getZ())  return true;
    else return false; 
}

bool Vector::isOrthogonal(const Vector& other) const
{
    if (isZero() || other.isZero()) {
        throw VectorLengthException();
    }

    // Two vectors are perpendicular when their dot product equals to 0
    return (*this * other) == 0;
}



// operators
Vector Vector::operator+(const Vector& other) const
{
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other) const
{
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(double a) const
{
    return Vector(x * a, y * a, z * a);
}

// scalar(dot) product
double Vector::operator*(const Vector& other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z);
}

// vector product
Vector Vector::operator^(const Vector& other) const
{
    
    return Vector(this->getY() *other.getZ() -this->getZ() *other.getY(), - this->getX() *other.getZ() +this->getZ() *other.getX(), this->getX() *other.getY() - this->getY() *other.getX());
}

// mixed product
double Vector::operator()(const Vector& a, const Vector& b)
{
    
    return a.getX() * b.getY() * this->getZ() + 
        a.getY() * b.getZ() * this->getX() +
        a.getZ() * b.getX() * this->getY() -
        a.getZ() * b.getY() * this->getX() - 
        a.getY() * b.getX() * this->getZ() - 
        a.getX() * b.getZ() * this->getY();
}

Vector operator*(double a, const Vector& vector)
{
    // polzvame nagotovo member operator*
    return vector * a;
}

