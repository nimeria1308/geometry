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
    return (abs(x - other.x) <= getPrecision())
        && (abs(y - other.y) <= getPrecision())
        && (abs(z - other.z) <= getPrecision());
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
