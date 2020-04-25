#include "Triangle.h"
#include "Exception.h"

using namespace geometry;
using namespace std;

// ctr/dtr
Triangle::Triangle()
{
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : a(a), b(b), c(c)
{
    // TODO
    // proverqvane za savpadashti tochki i
    // hvarlqne na izkliuchenie s obqsnenie
}

// methods
TriangleTypeSide Triangle::getTypeBySide() const
{
    // TODO
    return TRIANGLE_SCALENE;
}

TriangleTypeAngle Triangle::getTypeByAngle() const
{
    // TODO
    return TRIANGLE_ACUTE;
}

double Triangle::area() const
{
    // TODO
    return 0;
}

double Triangle::perimeter() const
{
    // TODO
    return 0;
}

Point Triangle::medicentre() const
{
    // TODO
    return Point();
}

// getters
const Point& Triangle::getA() const
{
    return a;
}

const Point& Triangle::getB() const
{
    return b;
}

const Point& Triangle::getC() const
{
    return c;
}
// operators

// tochkata leji vav vatreshnostta na triagalnika
bool operator<(const geometry::Point& point, const Triangle& triangle)
{
    // TODO
    return true;
}

// tochkata leji izvan triagalnika
bool operator>(const geometry::Point& point, const Triangle& triangle)
{
    // TODO
    return true;
}

// tochkata leji varhu stranite na triagalnika
bool operator==(const geometry::Point& point, const Triangle& triangle);

ostream& operator<<(ostream& out, const Triangle& triangle)
{
    out << triangle.getA() << " " << triangle.getB() << " " << triangle.getC();

    return out;
}

istream& operator>>(istream& in, Triangle& triangle)
{
    Point a, b, c;
    in >> a >> b >> c;

    triangle = Triangle(a, b, c);

    return in;
}
