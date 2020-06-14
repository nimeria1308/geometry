#include <sstream>

#include "menus.h"
#include "Point.h"

using namespace std;
using namespace geometry;


PointsMenu::PointsMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

PointsMenu::~PointsMenu()
{
}

void PointsMenu::show()
{
	// main menu for points
	cout << "Operations on points" << endl;

	// initialize first point
	Point p1 = readPoint("Enter coordinates of a new point");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Check if two points are equal" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int)readNumber("Select an operation (0-1)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				Point p2 = readPoint("Enter coordinates of the second point");
				cout << format(p1) << (p1 == p2 ? " == " : " != ") << format(p2) << endl;
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
