#include "Point.h"

#include <iomanip>
#include <limits>

using namespace geometry;
using namespace std;

// ctr
Point::Point()
    : Point(0, 0, 0)
{
}

Point::Point(double x, double y, double z)
    : x(x), y(y), z(z)
{
}

// operators
bool Point::operator==(const Point& other) const
{
    return (abs(x - other.x) <= Point::sPrecision)
        && (abs(y - other.y) <= Point::sPrecision)
        && (abs(z - other.z) <= Point::sPrecision);
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

const double Point::DEFAULT_PRECISION = 0.001;

double Point::sPrecision = Point::DEFAULT_PRECISION;

double Point::getPrecision()
{
    return Point::sPrecision;
}

void Point::setPrecision(double precision)
{
    Point::sPrecision = precision;
}

ostream& operator<<(ostream& out, const Point& point)
{
    out << setprecision(numeric_limits<long double>::digits10 + 1)
        << point.getX() << " " << point.getY() << " " << point.getZ();

    return out;
}

istream& operator>>(istream& in, Point& point)
{
    double x, y, z;
    in >> x >> y >> z;
    point = Point(x, y, z);

    return in;
}
