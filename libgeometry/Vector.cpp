#include "Vector.h"

using namespace geometry;
using namespace std;

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
	// TODO
	return 0;
}

Vector Vector::direction() const
{
	// TODO
	return Vector();
}

bool Vector::isZero() const
{
	return x == 0 && y == 0 && z == 0;
}

bool Vector::isParallel(const Vector& other) const
{
	// TODO
	return true;
}

bool Vector::isPerpendicular(const Vector& other) const
{
	// TODO
	return true;
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

// scalar product
double Vector::operator*(const Vector& other) const
{
	// TODO
	return 0;
}

// vector product
Vector Vector::operator^(const Vector& other) const
{
	// TODO
	return Vector();
}

// mixed product
double Vector::operator()(const Vector& a, const Vector& b)
{
	// TODO
	return 0;
}

Vector operator*(double a, const Vector& vector)
{
	// polzvame nagotovo member operator*
	return vector * a;
}