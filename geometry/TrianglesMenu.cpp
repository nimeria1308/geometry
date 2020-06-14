#include <sstream>

#include "menus.h"
#include "Triangle.h"

using namespace std;
using namespace geometry;


TrianglesMenu::TrianglesMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

TrianglesMenu::~TrianglesMenu()
{
}

string typeBySideToString(TriangleTypeSide t)
{
	switch (t) {
	case TRIANGLE_EQUILATERAL:
		return "equilateral";

	case TRIANGLE_ISOSCELES:
		return "isosceles";

	case TRIANGLE_SCALENE:
		return "scalene";

	default:
		return "unknown";
	}
}

string typeByAngleToString(TriangleTypeAngle t)
{
	switch (t) {
	case TRIANGLE_ACUTE:
		return "acute";

	case TRIANGLE_OBTUSE:
		return "obtuse";

	case TRIANGLE_RIGHT:
		return "right";

	default:
		return "unknown";
	}
}

void TrianglesMenu::show()
{
	// main menu for triangles
	cout << "Operations on triangles" << endl;

	// initialize first triangle
	Triangle t1 = readTriangle("Enter coordinates of a new triangle");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Find triangle type" << endl;
			cout << "[ 2]: Find area of the triangle" << endl;
			cout << "[ 3]: Find perimeter of the triangle" << endl;
			cout << "[ 4]: Find centroid (medicentre) of the triangle" << endl;
			cout << "[ 5]: Check if a point is inside the area of the triangle" << endl;
			cout << "[ 6]: Check if a point is on the perimeter of the triangle" << endl;
			cout << "[ 7]: Check if a point is outside the triangle" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int)readNumber("Select an operation (0-7)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				cout << "This is a " << typeBySideToString(t1.getTypeBySide()) << " " << typeByAngleToString(t1.getTypeByAngle()) << " triangle" << endl;
				break;
			}

			case 2:
			{
				cout << "The area of the triangle is " << t1.area() << endl;
				break;
			}

			case 3:
			{
				cout << "The perimeter of the triangle is " << t1.perimeter() << endl;
				break;
			}

			case 4:
			{
				cout << "The centroid (medicentre) of the triangle is " << format(t1.centroid()) << endl;
				break;
			}

			case 5:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p < t1 ? " is" : " is NOT") << " inside the area of the triangle" << endl;
				break;
			}

			case 6:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p == t1 ? " is" : " is NOT") << " on the perimeter triangle" << endl;
				break;
			}

			case 7:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p > t1 ? " is" : " is NOT") << " outside the triangle" << endl;
				break;
			}

			default:
				cout << "Invalid operation " << op << endl;
				showOperations = true;
				continue;
			}
		}
		catch (const GeometryException& exception) {
			cout << "Operation failed: " << exception.what() << endl;
		}
	}
}
