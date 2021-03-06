#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include <cstdbool>
#include <iostream>

#include "Element.h"

namespace geometry
{
    class Point : public Element
    {
    public:
        // ctr/dtr
        Point();
        Point(double x, double y, double z);
        virtual ~Point() { }

        // operators
        bool operator==(const Point& other) const;

        // getters
        double getX() const;
        double getY() const;
        double getZ() const;

    protected:
        // fields
        double x;
        double y;
        double z;
    };
}

std::ostream& operator<<(std::ostream& out, const geometry::Point& point);
std::istream& operator>>(std::istream& in, geometry::Point& point);

#endif