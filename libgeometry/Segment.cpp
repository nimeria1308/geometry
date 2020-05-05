#include "Segment.h"

#include "Segment.h"

using namespace geometry;
using namespace std;

// ctr
Segment::Segment()
{
}

Segment::Segment(const Point& point1, const Point& point2)
    : Line(point1, point2), endPoint(point2)
{
}

// methods
double Segment::length() const
{
    // todo
    return 0;
}

Point Segment::middle() const
{
    return Point(x / endPoint.getX(), y / endPoint.getY() / y, z / endPoint.getZ());
}

// operators

bool Segment::operator==(const Segment& other) const
{
    return start() == other.start()
        && end() == other.end();
}

// proverqva dali leji na otsechkata
bool Segment::operator==(const Point& point) const
{
    // TODO
    return true;
}


// getters
const Point& Segment::end() const
{
    return endPoint;
}

bool operator==(const Point& point, const Segment& segment)
{
    return segment == point;
}

ostream& operator<<(ostream& out, const Segment& segment)
{
    out << (const Line&)(segment) << " " << segment.end();

    return out;
}

istream& operator>>(istream& in, Segment& segment)
{
    Line line;
    Point point;

    in >> line >> point;
    segment = Segment(line.start(), point);

    return in;
}
