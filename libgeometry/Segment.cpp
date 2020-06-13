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

    auto d = 0.0;

    d = sqrt(pow((endPoint.getX() - x), 2) + pow((endPoint.getY() - y ), 2) + pow((endPoint.getZ() - z), 2));

    if (d <= 0.0)
    {
        std::cerr << "The number is not positive, or it is exaclty ZERO!" << std::endl;
    }

    else if (d > 0.0)
    {
        return d;
    }
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

// proverqva dali leji na otsechkata --- !!!CHECK IF CORRECT!!!

bool Segment::operator==(const Point& point) const
{

    if (Line(start(),endPoint) + point)
    {
        if (this->x < endPoint.getX())
        {
            if (this->x < x < endPoint.getX() == true)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        else if (this->x > endPoint.getX())
        {
            if (endPoint.getX() < x < this->x)
            {
                return true;
            }

            else
            {
                return false;
            }
        }
    }

    return false;

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
