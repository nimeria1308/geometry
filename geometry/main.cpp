#include <iostream>

#include "Point.h"
#include "Vector.h"

using namespace geometry;
using namespace std;

int main()
{
    // test Point
    Point p(1, 2, 3.1415);

    cout << "point: " << p << endl;

    // test Vector
    Vector v(p);
    cout << "vector: " << v << endl;

    Vector v2(p, Point(0.5, 1, 2));
    cout << "vector2: " << v2 << endl;
}
