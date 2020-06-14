#include "Line.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace geometry;
using namespace std;

// Default constructor.
Line::Line()
{
}

// Constructor with one vector and one point.
Line::Line(const Point& point, const Vector& vector)
    : Vector(point), directionVector(vector.direction())
{
}

// Constructor with two points.
Line::Line(const Point& p1, const Point& p2)
    : Line(p1, Vector(p1, p2))
{
}

// Methods:

const Point& Line::start() const
{
    return *this;
}

// Return the direction vector.
Vector Line::direction() const
{
    return directionVector;
}

// Returns the normal vector.
Vector Line::normal() const
{
    if (getX() == 0) {
        return Vector(1,0,0);
    }
    else if (getY() == 0) {
        return Vector(0,1,0);
    }
    else if (getZ() == 0) {
        return Vector(0,0,1);
    }

    //Flipping the original vector by 90 degrees.
    return Vector(-getY(), getX(), getZ());
}

// Return angle in radiants between two lines.
double Line::angle(const Line& other) const
{   
    return ((*this)*other) / (length() * other.length());
}

// Operators:

// If point lies on line.
bool Line::operator+(const Point& point) const
{
    double A1 = (point.getX() - getX()) / directionVector.getX();
    double A2 = (point.getY() - getY()) / directionVector.getY();
    double A3 = (point.getZ() - getZ()) / directionVector.getZ();

    return (A1 == A2 && A2 == A3);
}

// If two lines are parallel.
bool Line::operator||(const Line& other) const
{
    return directionVector.isParallel(other.directionVector);
}

// If two lines are coincide.
bool Line::operator==(const Line& other) const
{
    // Comparing coordinates of points and the angle of the vectors.
    return ((const Point&)*this) == ((const Point&)other)
        && (directionVector == other.directionVector);
}

// If two lines intersect.
bool Line::operator&&(const Line& other) const
{
    return ((directionVector ^ other.directionVector) * (*this - other)
        == 0);
}

// If two lines are crossed.
bool Line::operator!=(const Line& other) const
{
    return (!(*this == other) 
        && isParallel(other));
}

// If two lines are perpendicular.
bool Line::operator|(const Line& other) const
{
    return (angle(other) == M_PI/2);
}

bool operator+(const Point& point, const Line& line)
{
    return line + point;
}

// I/O

ostream& operator<<(ostream& out, const Line& line)
{
    out << (const Point&)(line) << " " << line.direction();

    return out;
}

istream& operator>>(istream& in, Line& line)
{
    Point point;
    Vector vector;

    in >> point >> vector;
    line = Line(point, vector);

    return in;
}
