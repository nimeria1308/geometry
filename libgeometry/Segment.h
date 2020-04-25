#ifndef GEOMETRY_SEGMENT_H
#define GEOMETRY_SEGMENT_H

#include "Line.h"
#include "Point.h"

namespace geometry
{
    class Segment : public Line
    {
    public:
        // ctr/dtr
        Segment();
        Segment(const Point& point1, const Point& point2);
        virtual ~Segment() { }

        // methods
        double length() const;
        Point middle() const;

        // operators

        // proverqva dali leji na otsechkata
        bool operator==(const Point& point) const;

        // getters
        const Point& end() const;

    protected:
        Point endPoint;
    };

}

bool operator==(const geometry::Point& point, const geometry::Segment& segment);
std::ostream& operator<<(std::ostream& out, const geometry::Segment& segment);
std::istream& operator>>(std::istream& in, geometry::Segment& segment);

#endif
