#include "Tetrahedron.h"
#include "Exception.h"

using namespace geometry;
using namespace std;

// ctr/dtr
Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d)
    : a(a), b(b), c(c), d(d)
{
    // TODO
    // proverqvane za savpadashti tochki i
    // hvarlqne na izkliuchenie s obqsnenie
}

// methods
bool Tetrahedron::isRegular() const
{
    // TODO
    return true;
}

bool Tetrahedron::isOrthogonal() const
{
    // TODO
    return true;
}

double Tetrahedron::area() const
{
    // TODO
    return 0;
}

double Tetrahedron::perimeter() const
{
    // TODO
    return 0;
}


// getters
const Point& Tetrahedron::getA() const
{
    return a;
}

const Point& Tetrahedron::getB() const
{
    return b;
}

const Point& Tetrahedron::getC() const
{
    return c;
}

const Point& Tetrahedron::getD() const
{
    return d;
}

// operators
bool Tetrahedron::operator==(const Tetrahedron& other) const
{
    // TODO: Should compare all combiantions
    return a == other.a
        && b == other.b
        && c == other.c
        && d == other.d;
}

// tochkata leji vav vatreshnostta na tetraedura
bool operator<(const Point& point, const Tetrahedron& tetrahedron)
{
    // TODO
    return true;
}

bool operator>(const Tetrahedron& tetrahedron, const Point& point)
{
    return point < tetrahedron;
}

// tochkata leji izvan tetraedura
bool operator>(const Point& point, const Tetrahedron& tetrahedron)
{
    // TODO
    return true;
}

bool operator<(const Tetrahedron& tetrahedron, const Point& point)
{
    return point > tetrahedron;
}

// tochkata leji varhu stranite na tetraedura
bool operator==(const Point& point, const Tetrahedron& tetrahedron)
{
    // TODO
    return true;
}

// tochkata leji varhu stranite na tetraedura
bool operator==(const Tetrahedron& tetrahedron, const Point& point)
{
    return point == tetrahedron;
}

ostream& operator<<(ostream& out, const Tetrahedron& tetrahedron)
{
    out << tetrahedron.getA() << " " << tetrahedron.getB() << " "
        << tetrahedron.getC() << " " << tetrahedron.getD();

    return out;
}

istream& operator>>(istream& in, Tetrahedron& tetrahedron)
{
    Point a, b, c, d;
    in >> a >> b >> c >> d;

    tetrahedron = Tetrahedron(a, b, c, d);

    return in;
}
