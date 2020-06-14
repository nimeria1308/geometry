#include "Triangle.h"
#include "Segment.h"



using namespace geometry;
using namespace std;

// ctr/dtr
Triangle::Triangle()
{
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: a(a), b(b), c(c)
{
	// !Проверка дали съвпадат точките на триъгълника!

	if (a == c && b == a && c == b)
	{
		throw
			EqualPointException("Points of triangle are equal");
	}

	else if (!(a == c && b == a && c == b))
	{
			EqualPointException("Points of triangle are not equal!");
	}

}

// methods
TriangleTypeSide Triangle::getTypeBySide() const
{
	// TODO

	return TriangleTypeSide::TRIANGLE_SIDES_UNKNOWN;
}

TriangleTypeAngle Triangle::getTypeByAngle() const
{
	// TODO
	return TriangleTypeAngle::TRIANGLE_ANGLES_UNKNOWN;
}

//Изчислява с Хероновата формула за лицето на триъгълника - връща лицето на 3-D триъгълника
double Triangle::area() const
{

	auto p = 0.0;

	p = (Segment(a, b).length() + Segment(b, c).length() + Segment(a, c).length()) / 2;

	return sqrt(p * (p - Segment(a, b).length()) * (p - Segment(b, c).length()) * (p - Segment(a, c).length()));

}

//Изчислява параметъра на триъгълника с помощта на класа Segment където се задават арргументите като променливи и връщат параметъра с дефинираната фунцкия length
double Triangle::perimeter() const
{
	Segment AB(a, b);
	Segment AC(a, c);
	Segment BC(b, c);

	return AB.length() + AC.length() + BC.length();
}

//Изчислява триъгълника чрез зададените формули и връща чрез обект тип Point координатите на А, B и С
Point Triangle::centroid() const
{
	auto coordinateA = (a.getX() + a.getY() + a.getZ()) / 3;
	auto coordinateB = (b.getX() + b.getY() + b.getZ()) / 3;
	auto coordinateC = (c.getX() + c.getY() + c.getZ()) / 3;


	return Point(coordinateA, coordinateB, coordinateC);

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
bool Triangle::operator==(const Triangle& other) const
{
	// TODO: Should compare all combinations
	return a == other.a
		&& b == other.b
		&& c == other.c;
}

// tochkata leji vav vatreshnostta na triagalnika
bool operator<(const Point& point, const Triangle& triangle)
{
	if (!Segment(triangle.getA(), triangle.getB()).operator==(point))
	{
		Triangle t1(triangle.getA(), triangle.getB(), point);
		Triangle t2(triangle.getA(), point, triangle.getC());
		Triangle t3(point, triangle.getB(), triangle.getC());
		
		return triangle.area() == (t1.area() + t2.area() + t3.area());
	}

	return false;
}

bool operator>(const Triangle& triangle, const Point& point)
{
	return point < triangle;
}

// tochkata leji izvan triagalnika
bool operator>(const Point& point, const Triangle& triangle)
{
	if (Segment(triangle.getA(), triangle.getB()).operator==(point))
	{
		Triangle t1(triangle.getA(), triangle.getB(), point);
		Triangle t2(triangle.getA(), point, triangle.getC());
		Triangle t3(point, triangle.getB(), triangle.getC());

		return triangle.area() < (t1.area() + t2.area() + t3.area());
	}

	return false;
}

bool operator<(const Triangle& triangle, const Point& point)
{
	return point > triangle;
}

// tochkata leji varhu stranite na triagalnika
bool operator==(const Point& point, const Triangle& triangle)
{

	if (Segment(triangle.getA(), triangle.getB()).operator==(point) || Segment(triangle.getA(), triangle.getC()).operator==(point) || Segment(triangle.getC(), triangle.getB()).operator==(point))
	{
		return true;
	}

	return false;
}

// tochkata leji varhu stranite na triagalnika
bool operator==(const Triangle& triangle, const Point& point)
{
	return point == triangle;
}

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

