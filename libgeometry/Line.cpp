#include "Line.h"

using namespace geometry;
using namespace std;

// ctr
Line::Line()
{
}

Line::Line(const Point& point, const Vector& vector)
    : Vector(point), directionVector(vector.direction())
{
}

Line::Line(const Point& p1, const Point& p2)
    : Line(p1, Vector(p1, p2))
{
}

// methods

const Point& Line::start() const
{
    return *this;
}

// direction
Vector Line::direction() const
{
    return directionVector;
}

// normal vector
Vector Line::normal() const
{
    // TODO
    return Vector();
}

// angle in radians between the two lines
double Line::angle(const Line& other) const
{
    // TODO
    return 0;
}

// operators

// tochka leji na prava
bool Line::operator+(const Point& point) const
{
    // TODO
    return true;
}

// usporednost na pravi
bool Line::operator||(const Line& other) const
{
    return directionVector.isParallel(other.directionVector);
}

// dali suvpadat
bool Line::operator==(const Line& other) const
{
    // sravnqvame gi kato tochki purvo i posle tehnite posoki
    return ((const Point&)*this) == ((const Point&)other)
        && (directionVector == other.directionVector);
}

// dali se presichat
bool Line::operator&&(const Line& other) const
{
    // TODO
    return true;
}

// dali sa krastosani
bool Line::operator!=(const Line& other) const
{
    // TODO
    return true;
}

// dali sa perpendikuliarni
bool Line::operator|(const Line& other) const
{
    // TODO
    return true;
}

bool operator+(const Point& point, const Line& line)
{
    return line + point;
}

// io

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
