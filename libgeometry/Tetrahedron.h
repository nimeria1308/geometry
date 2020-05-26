#ifndef GEOMETRY_TETRAHEDRON_H
#define GEOMETRY_TETRAHEDRON_H

#include <cstdbool>
#include <iostream>

#include "Element.h"
#include "Point.h"

namespace geometry
{
    class Tetrahedron : public Element {
    public:
        // ctr/dtr
        Tetrahedron();
        Tetrahedron(const Point& a, const Point& b, const Point& c, const Point &d);
        virtual ~Tetrahedron() { }

        // methods
        // dali e pravilen, t.e. vsichki ugli sa ravni,
        // t.e. vsichki lica sa ravnostranni triugulnici
        bool isRegular() const;

        // dali e ortogonalen, t.e. vseki dva sreshtupolojni ruba
        // sa perpendikuliarni
        bool isOrthogonal() const;

        double area() const;
        double perimeter() const;

        // operators
        bool operator==(const Tetrahedron& tetrahedron) const;

        // getters
        const Point& getA() const;
        const Point& getB() const;
        const Point& getC() const;
        const Point& getD() const;

    protected:
        Point a;
        Point b;
        Point c;
        Point d;
    };
}

// tochkata leji vav vatreshnostta na tetraedura
bool operator<(const geometry::Point& point, const geometry::Tetrahedron& tetrahedron);
bool operator>(const geometry::Tetrahedron& tetrahedron, const geometry::Point& point);

// tochkata leji izvan tetraedura
bool operator>(const geometry::Point& point, const geometry::Tetrahedron& tetrahedron);
bool operator<(const geometry::Tetrahedron& tetrahedron, const geometry::Point& point);

// tochkata leji varhu stranite na tetraedura
bool operator==(const geometry::Point& point, const geometry::Tetrahedron& tetrahedron);
bool operator==(const geometry::Tetrahedron& tetrahedron, const geometry::Point& point);

std::ostream& operator<<(std::ostream& out, const geometry::Tetrahedron& tetrahedron);
std::istream& operator>>(std::istream& in, geometry::Tetrahedron& tetrahedron);

#endif