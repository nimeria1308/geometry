#include <iostream>

#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"

using namespace geometry;
using namespace std;

int main()
{
    // TODO
    // MAIN APP

    // test Point
    Point p(1, 2, 3.1415);

    cout << "point: " << p << endl;

    // test Vector
    Vector v(p);
    cout << "vector: " << v << endl;

    Vector v2(p, Point(2, 7, 10));
    cout << "vector2: " << v2 << endl;

    Line l(p, v2);
    cout << "line: " << l << endl;

    Segment s(Point(10, 20, 30), Point(30, 40, 50));
    cout << "segment: " << s << endl;

    Triangle tr(Point(1, 2, 3), Point(10, 20, 30), Point(0, 30, 50));
    cout << "triangle: " << tr << endl;
}
