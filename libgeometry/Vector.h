#ifndef GEOMETRY_VECTOR_H
#define GEOMETRY_VECTOR_H

#include "Point.h"

namespace geometry
{
    class Vector : public Point
    {
    public:
        // ctr/dtr
        Vector();
        Vector(const Point& point);
        Vector(double x, double y, double z);
        Vector(const Point& p1, const Point& p2);
        virtual ~Vector() { }

        // methods
        double length() const;
        Vector direction() const;
        bool isZero() const;
        bool isParallel(const Vector& other) const;
        bool isPerpendicular(const Vector& other) const;

        // operators
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(double a) const;

        // scalar product
        double operator*(const Vector& other) const;

        // vector product
        Vector operator^(const Vector& other) const;

        // mixed product
        double operator()(const Vector& a, const Vector& b);

        // nqma nujda ot getters: unasledqvame ot Point
    };

    // double * Vector moje da bude samo non-member
    Vector operator*(double a, const Vector& vector);

    // nqma nujda da predefiniraame << i >>, tai
    // kato mojem da polzvame tezi za Point nagotovo
}

#endif