#ifndef GEOMETRY_TRIANGLE_H
#define GEOMETRY_TRIANGLE_H

#include <cstdbool>
#include <iostream>

#include "Element.h"
#include "Point.h"

namespace geometry
{
    enum TriangleTypeSide {
        TRIANGLE_SIDES_UNKNOWN,
        TRIANGLE_EQUILATERAL,	// ravnostranen: 3 ravni strani
        TRIANGLE_ISOSCELES,		// ravnobedren: 2 ravni strani
        TRIANGLE_SCALENE,		// nqma ravni strani
    };

    enum TriangleTypeAngle {
        TRIANGLE_ANGLES_UNKNOWN,
        TRIANGLE_RIGHT,  // prav: ima 1 prav (=90) agal
        TRIANGLE_OBTUSE, // tap: ima 1 tap (>90) agal
        TRIANGLE_ACUTE,  // ostar: ima 3 ostri (<90) agala
    };

    class Triangle : public Element {
    public:
        // ctr/dtr
        Triangle();
        Triangle(const Point& a, const Point& b, const Point& c);
        virtual ~Triangle() { }

        // methods
        TriangleTypeSide getTypeBySide() const;
        TriangleTypeAngle getTypeByAngle() const;
        double area() const;
        double perimeter() const;
        // medicenter
        Point centroid() const;

        // operators
        bool operator==(const Triangle& triangle) const;

        // getters
        const Point& getA() const;
        const Point& getB() const;
        const Point& getC() const;

    protected:
        Point a;
        Point b;
        Point c;
    };
}

// tochkata leji vav vatreshnostta na triagalnika
bool operator<(const geometry::Point& point, const geometry::Triangle& triangle);

// tochkata leji izvan triagalnika
bool operator>(const geometry::Point& point, const geometry::Triangle& triangle);

// tochkata leji varhu stranite na triagalnika
bool operator==(const geometry::Point& point, const geometry::Triangle& triangle);
bool operator==(const geometry::Triangle& triangle, const geometry::Point& point);

std::ostream& operator<<(std::ostream& out, const geometry::Triangle& triangle);
std::istream& operator>>(std::istream& in, geometry::Triangle& triangle);

#endif