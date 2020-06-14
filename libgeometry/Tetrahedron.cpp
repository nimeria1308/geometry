#include "Tetrahedron.h"



using namespace geometry;
using namespace std;

// ctr/dtr
Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d)
    : a(a), b(b), c(c), d(d)
{
    
        // Check for equal point exception.
        if (a == b || a == c || a == d || b == c || b == d || c == d)
        {
            throw EqualPointException("Tetrahedron can't be initialized, there are points that are equal.");
        }

    edge = Vector(a, b);
    edge2 = Vector(a, c);
    edge3 = Vector(a, d);
    edge4 = Vector(b, c);
    edge5 = Vector(b, d);
    edge6 = Vector(c, d);
}

// methods
bool Tetrahedron::isRegular()
{
    // all edges must be equal 
    return  (edge.length() == edge2.length() == edge3.length() == edge4.length() == edge5.length() == edge6.length());
}

bool Tetrahedron::isOrthogonal() const
{
    // If any 3 vectors with the same point are orthogonal between them, then the tetrahedron is orthogonal.
    //d
    if (Vector(a, d).isOrthogonal(Vector(b, d)) && Vector(a, d).isOrthogonal(Vector(c, d)) && Vector(b, d).isOrthogonal(Vector(c, d))) {
        return true;
    }
    //c
    if (Vector(a, c).isOrthogonal(Vector(b, c)) && Vector(a, c).isOrthogonal(Vector(d, c)) && Vector(b, c).isOrthogonal(Vector(d, c))) {
        return true;
    }
    //b
    if (Vector(a, b).isOrthogonal(Vector(c, b)) && Vector(d, b).isOrthogonal(Vector(c, b)) && Vector(a, b).isOrthogonal(Vector(d, b))) {
        return true;
    }
    //a
    if (Vector(d, a).isOrthogonal(Vector(c, a)) && Vector(d, a).isOrthogonal(Vector(b, a)) && Vector(c, a).isOrthogonal(Vector(b, a))) {
        return true;
    }
    return false;
}

double Tetrahedron::area() const
{

    //The area of tetrahedron is the determinant of 3 Vectors
    return abs(edge.getX() * edge2.getY() * edge3.getZ()
        + edge.getY() * edge2.getZ() * edge3.getX()
        + edge.getZ() * edge2.getX() * edge3.getY()
        - edge.getZ() * edge2.getY() * edge3.getX()
        - edge.getX() * edge2.getZ() * edge3.getY()
        - edge.getY() * edge2.getX() * edge3.getZ());

}

double Tetrahedron::perimeter() const
{
    // The surface of tetrahedron is equal to the sum of areas of it's triangles

    double t1 = Triangle(a, b, c).area();
    double t2 = Triangle(a, b, d).area();
    double t3 = Triangle(a, c, d).area();
    double t4 = Triangle(b, c, d).area();
    return t1+t2+t3+t4;
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

// Point lying inside of the tetrahedron
bool operator<(const Point& point, const Tetrahedron& tetrahedron)
{
    // checking first if the point lies on the tetrahedron
    if (point == tetrahedron)
    {
        // initializing 4 tetrahedrons (with 3 points from the main tetrahedron and the point that's been checked) 
        // to check if their combined area is < than the main tetrahedron area
        Tetrahedron t(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getC(), point);
        Tetrahedron t2(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getD(), point);
        Tetrahedron t3(tetrahedron.getA(), tetrahedron.getC(), tetrahedron.getD(), point);
        Tetrahedron t4(tetrahedron.getB(), tetrahedron.getC(), tetrahedron.getD(), point);

        // if it's " < " then the point lies inside of the tetrahedron.
        if (tetrahedron.area() - (t.area() + t2.area() + t3.area() + t4.area()) < 0.01)
        {
            return true;
        }
    }
        return false;
    
}

bool operator>(const Tetrahedron& tetrahedron, const Point& point)
{
    return point < tetrahedron;
}

// Point lying outside of the tetrahedron
bool operator>(const Point& point, const Tetrahedron& tetrahedron)
{
    // checking first if the point lies on the tetrahedron
    if (point == tetrahedron)
    {
        // initializing 4 tetrahedrons (with the point) to check if their combined area is > than the main tetrahedron area
        // if it's " > " then the point lies outside of the tetrahedron.
        Tetrahedron t(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getC(), point);
        Tetrahedron t2(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getD(), point);
        Tetrahedron t3(tetrahedron.getA(), tetrahedron.getC(), tetrahedron.getD(), point);
        Tetrahedron t4(tetrahedron.getB(), tetrahedron.getC(), tetrahedron.getD(), point);

        if (tetrahedron.area() - (t.area() + t2.area() + t3.area() + t4.area()) > 0.01)
        {
            return true;
        }
        return false;
    }
}

bool operator<(const Tetrahedron& tetrahedron, const Point& point)
{
    return point > tetrahedron;
}

// Point lying on the tetrahedron
bool operator==(const Point& point, const Tetrahedron& tetrahedron)
{
    // To check if point lies on the tetrahedron we check if it lies on any of it's triangles

   return (point < Triangle(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getC()) ||
        point < Triangle(tetrahedron.getA(), tetrahedron.getB(), tetrahedron.getD()) ||
        point < Triangle(tetrahedron.getA(), tetrahedron.getC(), tetrahedron.getD()) ||
        point < Triangle(tetrahedron.getB(), tetrahedron.getC(), tetrahedron.getD()));
}

// Point lying on the tetrahedron
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
